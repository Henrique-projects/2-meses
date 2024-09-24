const imagem = document.getElementById('img3');
const botao = document.getElementById('botao2');
const botao3 = document.getElementById('botao3');
const conteudo = document.getElementById('conteudo3');

botao.addEventListener('click', function(){

    botao3.classList.toggle('ajustarBotao');

    imagem.classList.toggle('ajustarImagem');

    conteudo.classList.toggle('ajustarCont');

});


function spin(img, cont){

        cont.classList.toggle('esconder');
        
        img.classList.toggle('girar');

};
