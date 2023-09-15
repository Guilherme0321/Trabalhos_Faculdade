document.querySelector("#formulario").addEventListener("submit", (e) => {

    let nome = document.querySelector("#nome").value;
    let cpf = document.querySelector("#cpf").value;
    let nacionalidade = document.querySelector("#nacionalidade").value;
    let genero = document.querySelector("#genero").value;
    let telefone = document.querySelector("#telefone").value;
    let estado_civil = document.querySelector("#estado-civil").value;
    let data_nascimento = document.querySelector("#data-nascimento").value;

    var xml = new XMLHttpRequest();

    xml.open("POST","http://localhost:8080/pessoa",true);
    xml.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");

    
    var data = `nome=${encodeURIComponent(nome)}&cpf=${encodeURIComponent(cpf)}&nacionalidade=${encodeURIComponent(nacionalidade)}&genero=${encodeURIComponent(genero)}&telefone=${encodeURIComponent(telefone)}&estado-civil=${estado_civil}&data-nascimento=${data_nascimento}`;

    xml.send(data);

});

document.querySelector("#form-get").addEventListener("submit", (e) => {
    e.preventDefault();
    let cpf = document.querySelector("#CPF-get").value;

    fetch(`http://localhost:8080/pessoa/id?cpf=${cpf}`)
    .then(response => {
        if (!response.ok) {
          throw new Error('Erro na requisição');
        }
        return response.text();
      })
      .then(data => {
        let splited = data.split('|');
        document.querySelector("#nome-get").value = splited[0];
        document.querySelector("#nacionalidade-get").value = splited[1];
        document.querySelector("#genero-get").value = splited[2];
        document.querySelector("#data-nascimento-get").value = splited[3];
        document.querySelector("#telefone-get").value = splited[4];
        document.querySelector("#estado-civil-get").value = splited[5];
      })
      .catch(error => {
        console.error('Erro:', error);
      });
});

document.querySelector("#alterar").addEventListener("click", () => {
    let CPF = document.querySelector("#CPF-get").value;
    let nome = document.querySelector("#nome-get").value;
    let nacionalidade = document.querySelector("#nacionalidade-get").value;
    let nascimento = document.querySelector("#data-nascimento-get").value;

    if(CPF != "" && nome != "" && nacionalidade != "" && nascimento != ""){
        var xml = new XMLHttpRequest();
        xml.open("POST","http://localhost:8080/pessoa/alterar",true);
        xml.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    
        
        var data = `cpf=${document.querySelectorAll("#form-get > input[type=text]")[0].value}&nome=${document.querySelectorAll("#form-get > input[type=text]")[1].value}&nacionalidade=${document.querySelectorAll("#form-get > input[type=text]")[2].value}&genero=${document.querySelectorAll("#form-get > input[type=text]")[3].value}&telefone=${document.querySelectorAll("#form-get > input[type=text]")[4].value}&estado-civil=${document.querySelectorAll("#form-get > input[type=text]")[5].value}&data-nascimento=${document.querySelectorAll("#form-get > input[type=text]")[6].value}`;
    
        xml.send(data);
        let form = document.querySelector("#form-get");
        form.submit();
    }
});

document.querySelector("#delete").addEventListener("submit", (e) => {
    e.preventDefault();
    let CPF = document.querySelector("#setar-delete").value;

    fetch(`http://localhost:8080/pessoa/delete?cpf=${CPF}`)
    .then(res => {
        if(!res.ok){
            throw new Error("Erro ao requisitar delete");
        }
        return res.text();
    }).then(dados => {
        console.log(dados);
    }).catch(erro => {
        console.error(erro);
    })
});