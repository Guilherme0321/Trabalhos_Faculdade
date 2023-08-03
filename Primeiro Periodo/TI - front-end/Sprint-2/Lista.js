

const info = {
    "Clientes":[
        {
            "id":[],
            "nome":[],
            "email":[],
            "senha":[]
        }
    ]
}
var z = 0;
var dados = info.Clientes[0];
const u = JSON.parse(localStorage.getItem('Dados'));

fetch('Lista.json')
  .then(response => response.json())
  .then(data => {
    const dadosJ = data.Clientes[0];
      if(u != null && u.id.includes(dadosJ.id)){
    dadosJ.id.forEach(i => {
        dadosJ.id.forEach(i => {
            dados.id.push(u.id[i-1]);
            dados.nome.push(u.nome[i-1]);
            dados.email.push(u.email[i-1]);
            dados.senha.push(u.senha[i-1]);
            mostrar();
        })
    })}else{
    dadosJ.id.forEach(i => {
        dados.id.push(dadosJ.id[i-1]);
        dados.nome.push(dadosJ.nome[i-1]);
        dados.email.push(dadosJ.email[i-1]);
        dados.senha.push(dadosJ.senha[i-1]);
    z++;
    mostrar();
})}
for(let g of dados.id){
    if(u.id.length <= dados.id.length && !u.id.includes(g) || u.id.length >= dados.id.length && dados.id.includes(u.id[g-1])){
        dados = u;
        z = Number(dados.id.length);
        mostrar();
    }
    
}
})
  document.querySelector("#txtID").addEventListener('input', () => {
    const V = document.querySelector("#txtID").value;
    if(V !== ''){
    const idV = Number(V);
    const i = dados.id.findIndex(item => item == idV);
    const nomeV = dados.nome[i];
    const emailV = dados.email[i];
    const senhaV = dados.senha[i];
    const VN = document.querySelector("#txtAL").value = nomeV;
    const VE = document.querySelector("#eAL").value = emailV;
    const VS = document.querySelector("#sAL").value = senhaV;
    document.getElementById('sAL').type = 'text'
    }else{
        document.querySelector("#txtAL").value = '';
        document.querySelector("#eAL").value = '';
        document.querySelector("#sAL").value = '';
    }
});

const enviar = document.getElementById('mostrar');
enviar.addEventListener('click', () => {
    tabM();
    mostrar();
});
function mostrar(){
    document.querySelectorAll('#tentativaE').forEach(y => {
        document.querySelector('tbody').removeChild(y)
    });
    for(let i = 0; i < dados.id.length;i++){
            const criar = document.createElement('tr');
        criar.classList.add(`${dados.id.length-1}`);
        criar.setAttribute('id','tentativaE');
        document.querySelector("#tabela > tbody").appendChild(criar);
            const dadosM = `
            <th>${dados.id[i]}</th>
            <th>${dados.nome[i]}</th>
            <th>${dados.email[i]}</th>
            <th>${dados.senha[i]}</th>
            `;
            document.querySelector("#tabela > tbody > tr:last-child").innerHTML = dadosM;
        };
} 

function tabM(){
    const nome = document.querySelector("#txt").value;
    const email = document.querySelector("#e").value;
    const senha = document.querySelector("#s").value;
    if(nome != '' && email != '' && senha != ''){
   
        if(!dados.id.includes(z)){
        dados.id.push(z);
        ++z;
    }else{
        z = z + 1;
        dados.id.push(z);
    }
    dados.email.push(email);
    dados.nome.push(nome);
    dados.senha.push(senha);    
    localStorage.setItem('Dados',JSON.stringify(dados));
    console.log(localStorage);

    }
    else{
        const frase = 'Preencha esse espaço!';
        document.getElementById('txt').placeholder = frase;
        document.getElementById('e').placeholder = frase;
        document.getElementById('s').placeholder = frase;
        }



}
const alt = document.querySelector("#alterar");
alt.addEventListener('click', () => {
    document.querySelector("#alt").style.display = 'block';
    document.querySelector("#adici").style.display = 'none';
    document.querySelector("#rev").style.display= 'none';
});


document.querySelector("#add").addEventListener('click', () => {
    document.querySelector("#adici").style.display = 'block';
    document.querySelector("#rev").style.display= 'none';
    document.querySelector("#alt").style.display = 'none';
});

document.querySelector("#remover").addEventListener('click', () => {
    document.querySelector("#adici").style.display = 'none';
    document.querySelector("#rev").style.display= 'block';
    document.querySelector("#alt").style.display = 'none';

});

document.querySelector("#delete").addEventListener('click', () => {
    const testando = document.querySelector("#txt1").value;
    if(dados.id.includes(Number(testando))){
    if(document.querySelector("#txt1").value != ''){
        window.alert('Certeza que deseja excluir essa informação?')
        const rev = Number(document.querySelector("#txt1").value);
        const y2 = dados.id[0]; const y3 = dados.id[dados.id.length -1];
        const n = dados.id.findIndex(item => item === rev);
        dados.id.splice(n,1);
        dados.nome.splice(n,1);
        dados.email.splice(n,1);
        dados.senha.splice(n,1);
        
        
        mostrar();
    
        document.querySelector("#txt1").value = '';
        document.querySelector("#txt1").placeholder = 'Removido com sucesso';
        localStorage.setItem('Dados',JSON.stringify(dados));
        console.log(localStorage);
    }else{
        document.querySelector("#txt1").placeholder = 'Preencha esse espaço';
    }
}else{
    document.querySelector("#txt1").value = '';
    document.querySelector("#txt1").placeholder = 'Esse ID não existe';
}
});
document.querySelector("#alte").addEventListener('click', () => {
    const x = Number(document.querySelector("#txtID").value);

    if(dados.id.includes(x)){
    const k = dados.id.findIndex(item => item == x);
    dados.nome[k] = document.querySelector("#txtAL").value;
    dados.email[k] = document.querySelector("#eAL").value
    dados.senha[k] = document.querySelector("#sAL").value;
    localStorage.setItem('Dados',JSON.stringify(dados));
    console.log(localStorage);

    mostrar();
}})
function limpar(){
    localStorage.clear();
    mostrar();
}