package arquivos;

import java.io.IOException;
import java.util.ArrayList;

import aeds3.Arquivo;
import aeds3.ArvoreBMais;
import aeds3.HashExtensivel;
import aeds3.ParIntInt;
import entidades.Livro;
import lista_invertida.ListaInvertida;

public class ArquivoLivros extends Arquivo<Livro> {

  HashExtensivel<ParIsbnId> indiceIndiretoISBN;
  ArvoreBMais<ParIntInt> relLivrosDaCategoria;
  ListaInvertida lista = new ListaInvertida();

  public ArquivoLivros() throws Exception {
    super("livros", Livro.class.getConstructor());
    indiceIndiretoISBN = new HashExtensivel<>(
        ParIsbnId.class.getConstructor(),
        4,
        "dados/livros_isbn.hash_d.db",
        "dados/livros_isbn.hash_c.db");
    relLivrosDaCategoria = new ArvoreBMais<>(ParIntInt.class.getConstructor(), 4, "dados/livros_categorias.btree.db");
    lista = new ListaInvertida(40, "listaDicionario.txt", "listaBlocos.txt");

  }

  @Override
  public int create(Livro obj) throws Exception {
    int id = super.create(obj);
    obj.setID(id);
    indiceIndiretoISBN.create(new ParIsbnId(obj.getIsbn(), obj.getID()));
    relLivrosDaCategoria.create(new ParIntInt(obj.getIdCategoria(), obj.getID()));

    String tituloSemStopWords = removerStopWords(obj.getTitulo());
    for (String palavra : tituloSemStopWords.split(" ")) {
      lista.create(palavra, id);
    }
   
    

    return id;
  }

  public Livro readISBN(String isbn) throws Exception {
    ParIsbnId pii = indiceIndiretoISBN.read(ParIsbnId.hashIsbn(isbn));
    if (pii == null)
      return null;
    int id = pii.getId();
    return super.read(id);
  }

  public ArrayList<Integer> countExpection(ArrayList<Integer> arr,int countExpected) {
    int count = 0;
    ArrayList<Integer> ids = new ArrayList<>();
    for(int i = 0; i < arr.size(); i++) {
      for(int j = 0; j < arr.size(); j++) {
        if(arr.get(i) == arr.get(j)) {
          count++;
        }
      }
      if(count == countExpected) {
        ids.add(arr.get(i));
      }
      count = 0;
    }
    return ids;
  }

  public ArrayList<Livro> searchByTitle(String title) throws Exception {
    String[] words = removerStopWords(title).split(" ");
    ArrayList<Livro> livros = new ArrayList<>();
    ArrayList<Integer> ids = new ArrayList<>();
    for (int i = 0; i < words.length; i++) {
      int[] tmp = lista.read(words[i]);
      for(int j : tmp) {
        ids.add(j);
      }
    }
    ArrayList<Integer> temp = countExpection(ids, words.length);
    for(int i = 0; i < temp.size(); i++) {
      livros.add(super.read(temp.get(i)));
    }

    return livros;
  }

  @Override
  public boolean delete(int id) throws Exception {
    Livro obj = super.read(id);
    if (obj != null)
      if (indiceIndiretoISBN.delete(ParIsbnId.hashIsbn(obj.getIsbn()))
          &&
          relLivrosDaCategoria.delete(new ParIntInt(obj.getIdCategoria(), obj.getID()))) {
            System.out.println(obj.getTitulo());
            String[] text = removerStopWords(obj.getTitulo()).split(" ");
            for (String string : text) {
              lista.delete(string, id);
            }
            return super.delete(id);
          }
    return false;
  }

  @Override
  public boolean update(Livro novoLivro) throws Exception {
    Livro livroAntigo = super.read(novoLivro.getID());
    if (livroAntigo != null) {

      boolean alterouTitulo = !(livroAntigo.getTitulo().equals(novoLivro.getTitulo()));
      if (alterouTitulo) {
        String tituloSemStopWords = removerStopWords(novoLivro.getTitulo());
        for (String palavra : tituloSemStopWords.split(" ")) {
          lista.create(palavra, novoLivro.getID());
        }

        String tituloAntigoSemStopWords = removerStopWords(livroAntigo.getTitulo());
        for (String palavra : tituloAntigoSemStopWords.split(" ")) {
          lista.delete(palavra, livroAntigo.getID());
        }
      }

      // Testa alteração do ISBN
      if (livroAntigo.getIsbn().compareTo(novoLivro.getIsbn()) != 0) {
        indiceIndiretoISBN.delete(ParIsbnId.hashIsbn(livroAntigo.getIsbn()));
        indiceIndiretoISBN.create(new ParIsbnId(novoLivro.getIsbn(), novoLivro.getID()));
      }

      // Testa alteração da categoria
      if (livroAntigo.getIdCategoria() != novoLivro.getIdCategoria()) {
        relLivrosDaCategoria.delete(new ParIntInt(livroAntigo.getIdCategoria(), livroAntigo.getID()));
        relLivrosDaCategoria.create(new ParIntInt(novoLivro.getIdCategoria(), novoLivro.getID()));
      }

      // Atualiza o livro
      return super.update(novoLivro);
    }
    return false;

  }

  public static String removerStopWords(String tituloLivro) throws IOException {
    var stopWords = ListaInvertida.loadStopwords();
    String[] palavras = tituloLivro.split(" ");
    StringBuilder novoTitulo = new StringBuilder();
    for (String palavra : palavras) {

      palavra = prepararPalavra(palavra);
      System.out.println(palavra);
      boolean isStopWord = stopWords.contains(palavra);
      if (!isStopWord) {
        System.out.println("Palavra: " + palavra);
        novoTitulo.append(palavra);
        novoTitulo.append(" ");
      }
    }
    return novoTitulo.toString().trim();
  }

  public static String prepararPalavra(String palavra) {
    palavra = palavra.toLowerCase();
    System.out.println(palavra);
    // remover caracteres especiais e replace acentos pelo caracter normal
    palavra = palavra.replace("ç", "c");
    palavra = palavra.replaceAll("[áàâã]", "a");
    palavra = palavra.replaceAll("[éèê]", "e");
    palavra = palavra.replaceAll("[íìî]", "i");
    palavra = palavra.replaceAll("[óòôõ]", "o");
    palavra = palavra.replaceAll("[úùû]", "u");
    palavra = palavra.replaceAll("[^a-zA-Z0-9]", "");
    palavra = palavra.trim();

    return palavra;
  }

}
