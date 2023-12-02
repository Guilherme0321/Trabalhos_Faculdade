let pedido = {
    bebidas: [],
    sabores: []
};

function getPedido(){
    let sabores = document.querySelector("#pizzaGrid > div").children;
    
    for( let i of sabores ){
        let infos = i.children
        let tamanho = infos['size-pizza'].value
        let nome = infos[0].textContent
        let quantidade = infos[5].children[1].textContent
        if(quantidade > 0){
            let pizzas = {
                nome: nome,
                tamanho: tamanho,
                quantidade: quantidade
            }
            pedido.sabores.push(pizzas);
        }
    }
    
    let bebidas = document.querySelector("#pizzaGrid > div:nth-child(8)").children;
    
    for( let i of bebidas ){
        let infos = i.children;
        let nome = infos[0].textContent
        let quantidade = infos[3].children[1].textContent
        if(quantidade > 0){
            let bebida = {
                nome: nome,
                quantidade: quantidade
            }
            pedido.bebidas.push(bebida)
        }
    }
}

document.querySelector("#Button_Enviar_Pedido").addEventListener("click", () => {
    if (!localStorage.getItem('usuario')) {
        alert('Não esta cadastrado no sistema, é necessário ter um cadastro para fazer o pedido!');
    }else{
        getPedido();
        if(pedido.bebidas.length > 0 || pedido.sabores.length > 0){
            localStorage.setItem('pedido', JSON.stringify(pedido));
            window.location.href = 'carrinho.html';
        }else{
            alert("Precisa ter pelo menos um item para realizar enviar o pedido!");
        }
    }
})

let historico = JSON.parse(localStorage.getItem('historicoPedidos'));
historico.forEach(pedido => {
     let tempItem = "";
Object.values(pedido).forEach(x => {
   
        x.forEach(item => {
            if(item.tamanho){
                tempItem += `<li>- ${item.quantidade}x ${ item.nome}(${item.tamanho})</li>`;
            }else{
                tempItem += `<li>- ${item.quantidade}x ${ item.nome}</li>`;
            }


});
})
         document.querySelector("body > div.menu_pizza > div.order-history").innerHTML += '<ul>' + tempItem + '</ul><hr>';
})