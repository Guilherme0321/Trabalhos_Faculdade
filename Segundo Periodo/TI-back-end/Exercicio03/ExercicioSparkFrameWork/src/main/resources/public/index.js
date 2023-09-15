document.querySelector("#formulario").addEventListener("submit", (e) => {

    let nome = document.querySelector("#nome").value;
    let cpf = document.querySelector("#cpf").value;
    let nacionalidade = document.querySelector("#nacionalidade").value;
    let genero = document.querySelector("#genero").value;
    let telefone = document.querySelector("#telefone").value;
    let estado_civil = document.querySelector("#estado-civil").value;
    let data_nascimento = document.querySelector("#data-nascimento").value;

    var xml = new XMLHttpRequest();

    xml.open("POST","http://localhost:8080/produto",true);
    xml.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");

    
    var data = `nome=${encodeURIComponent(nome)}&cpf=${encodeURIComponent(cpf)}&nacionalidade=${encodeURIComponent(nacionalidade)}&genero=${encodeURIComponent(genero)}&telefone=${encodeURIComponent(telefone)}&estado-civil=${estado_civil}&data-nascimento=${data_nascimento}`;

    xml.send(data);

});