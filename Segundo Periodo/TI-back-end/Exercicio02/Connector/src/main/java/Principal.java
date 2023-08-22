import java.util.ArrayList;

public class Principal {
	
	public static void main(String[] args) {
		String url = "jdbc:postgresql://localhost:5432/Users", user = "postgres", senha = "senha123";
		DAO con = new  DAO(url, user, senha);
		con.Listar("usuarios");
		ArrayList<Users> usuarios = con.getList();
		for(Users usuario: usuarios) {
			System.out.println(usuario);
		}
		con.Inserir("usuarios", "Leonardo", "Silva", "leonardo.silva@gmail.com", "senha123");
		con.Deletar("usuarios", 25);
		con.Atualizar("usuarios", "nome", "Rodrigo", 20);
		con.Sair();
	}

}
