var titulo = document.querySelector("#titulo").value;
let informacoes = JSON.parse(localStorage.getItem('informacoes'));
var Notification = [];
if (informacoes) {
  informacoes.forEach(x => {
    Notification.push(x);
  });
}
// criar as tags da barra de animação
function removerBArra() {
  document.querySelectorAll(".body").forEach(x => {
    x.remove();
  })
}

function criarBARRA() {
  const NOTIFICATIONBAR = document.createElement('header');
  NOTIFICATIONBAR.classList.add('notificationBar');

  document.querySelector("body").insertBefore(NOTIFICATIONBAR, document.querySelector("body").firstChild);

  const NOTIFICATIONICON = document.createElement('div');
  NOTIFICATIONICON.classList.add('notificationIcon');
  NOTIFICATIONBAR.appendChild(NOTIFICATIONICON);

  const imageICONS = document.createElement('img');
  imageICONS.classList.add('notificar');
  imageICONS.setAttribute('width', '40px');
  imageICONS.setAttribute('height', '40px');
  imageICONS.src = 'bell.png';
  NOTIFICATIONICON.appendChild(imageICONS);

  const FECHAR = document.createElement('div');
  FECHAR.classList.add('fecharNoti');
  NOTIFICATIONBAR.appendChild(FECHAR);

  const imageFECHAR = document.createElement('img');
  imageFECHAR.setAttribute('width', '15');
  imageFECHAR.src = 'close.png';
  FECHAR.appendChild(imageFECHAR);

  const NumeroDeNotificacoes = document.createElement('div');
  NumeroDeNotificacoes.classList.add('numerosDeNotificacao');
  NOTIFICATIONBAR.appendChild(NumeroDeNotificacoes);
}
criarBARRA();
// chamar a funcao a cada 5s para testar a hora e data
var testarDATA = setInterval(GethourNow, 2000);

function pegarDatadeAgora() {
  let diaHJ = new Date().getDate();
  if (Number(diaHJ) < 10) {
    diaHJ = '0' + diaHJ;
  }
  let mesNow = new Date().getMonth() + 1;
  if (Number(mesNow) < 10) {
    mesNow = '0' + mesNow;
  }
  let anoNow = new Date().getFullYear();
  let dataCompleta = `${anoNow}-${mesNow}-${diaHJ}`;
  return dataCompleta;
}

function GethourNow() {
  if (Notification.length == 0) {
    clearInterval(testarDATA);
    return 0;
  }
  let data = new Date();
  let horaNow = data.getHours();
  if (Number(horaNow) < 10) {
    horaNow = '0' + horaNow;
  }
  let minutos = data.getMinutes();
  if (Number(minutos) < 10) {
    minutos = '0' + minutos
  }
  let horasCompleta = `${horaNow}:${minutos}`;

  let dataCompleta = pegarDatadeAgora();
  Notification = Notification.filter(a => a.horario >= horasCompleta && a.data >= dataCompleta);
  let novaNot = Notification.filter((a) => a.horario == horasCompleta && a.data == dataCompleta);
  if (novaNot.length > 0) {
    novaNot.forEach((x) => {
      notification(x);
      let p = Notification.indexOf(x);
      Notification = Notification.filter(a => a != x);
      localStorage.setItem('informacoes', JSON.stringify(Notification));
    });
  }
}

//animacao do sino da notificacao
const sino = document.querySelector(".notificar");
sino.addEventListener('click', () => {
const quantidadeNotes = document.querySelector(".numerosDeNotificacao");
  quantidadeNotes.textContent = '';
  quantidadeNotes.style.display = 'none';
  if (sino.classList.contains('notificarOpen')) {
    sino.classList.remove('notificarOpen');
    document.querySelectorAll(".body").forEach(ele => {
      if (ele.classList.contains('TirarNotificar')) {
        ele.classList.remove('TirarNotificar');
        ele.classList.add('abrirNotificar');
      } else {
        ele.classList.remove('abrirNotificar');
        ele.classList.add('TirarNotificar');
      }
    });
  } else {
    sino.classList.add('notificarOpen');
    document.querySelectorAll(".body").forEach(ele => {
      if (ele.classList.contains('TirarNotificar')) {
        ele.classList.remove('TirarNotificar');
        ele.classList.add('abrirNotificar');
      } else {
        ele.classList.remove('abrirNotificar');
        ele.classList.add('TirarNotificar');
      }
    });
  }
});
// Animacao da notificacao saindo
document.querySelector(".fecharNoti").addEventListener('click', () => {
  document.querySelector(".notificationBar").classList.remove('DescerNotificar');
  document.querySelector(".notificationBar").classList.add('chamarAnimacao');
  setTimeout(voltarORIGINAL, 5000);
})
function voltarORIGINAL() {
  document.querySelector(".notificationBar").classList.remove('chamarAnimacao');
  document.querySelector(".notificar").classList.remove('notificarOpen')
  removerBArra();
}

function notification(x) {
  const header = document.createElement('div');
  header.classList.add('body');
    if (sino.classList.contains('notificarOpen')) {
        header.classList.add('abrirNotificar');
    }else{
        header.classList.add('TirarNotificar');
    }
  const titulo = document.createElement('h1');
  titulo.classList.add('title');
  titulo.textContent = 'Lembrete de Tarefa';

  header.appendChild(titulo);

  const horaAgora = document.createElement('p');
  horaAgora.classList.add('horarioAgora');
  const txt = `<strong>${x.horario}</strong>`;
  horaAgora.innerHTML = txt;
  header.appendChild(horaAgora);

  const conteudo = document.createElement('p');
  conteudo.textContent = x.titulo;
  conteudo.classList.add('conteudo');
  header.appendChild(conteudo);

  let corpoDaNotificar = document.querySelector(".notificationBar");
  let segundo = corpoDaNotificar.children[1];
  corpoDaNotificar.insertBefore(header, segundo);
  document.querySelector("header.notificationBar").classList.add('DescerNotificar');
  /* const body = document.querySelector("body"); */
  /*  body.insertBefore(header,body.firstChild); */ // insere como o primeiro elemento da tag body
  const quantidadeNotes = document.querySelector(".numerosDeNotificacao");
  quantidadeNotes.style.display = 'flex';
  quantidadeNotes.textContent = document.querySelectorAll(".body").length
}

// Parte da area de teste
document.querySelector("#areaTeste").addEventListener('click', () => {
  const areaTeste = document.querySelector(".compromisso");
  const icone = document.querySelector("#areaTeste img");

  const blur = document.querySelector("#blur");
  if (areaTeste.classList.contains('mostrar')) {
    areaTeste.classList.remove('mostrar');
  } else {
    areaTeste.classList.add('mostrar');
  }
  if (blur.classList.contains('tirarblur')) {
    blur.classList.remove('tirarblur');
  } else {
    blur.classList.add('tirarblur');
  }

  if (!icone.classList.contains('rodar')) {
    icone.classList.add('rodar');
  } else {
    icone.classList.remove('rodar');
  }
});

document.querySelector("#areaTeste").addEventListener('click', () => {
  let diaHJ = new Date().getDate();
  if (Number(diaHJ) < 10) {
    diaHJ = '0' + diaHJ;
  }
  let mesNow = new Date().getMonth() + 1;
  if (Number(mesNow) < 10) {
    mesNow = '0' + mesNow;
  }
  let anoNow = new Date().getFullYear();
  let dataCompleta = `${anoNow}-${mesNow}-${diaHJ}`;
  document.querySelector("#horario").setAttribute('min', `${dataCompleta}`);
});

document.querySelector("#form").addEventListener('submit', (e) => {
  const title = document.querySelector("#titulo").value;

  const hora = document.querySelector("#hora").value;

  const data = document.querySelector("#horario").value;

  let newNotification = {
    titulo: title,
    horario: hora,
    data: data
  };

  Notification.push(newNotification);

  localStorage.setItem('informacoes', JSON.stringify(Notification));
  alert("Tarefa enviada!");
});

document.querySelector("#getData").addEventListener('click', () => {
  let data = pegarDatadeAgora();
  document.querySelector("#horario").value = data;
});
//animação do fundo
const tl = gsap.timeline();

const Line = $el => {
  const $paths = $el.querySelectorAll(".path");
  const tl = gsap.timeline();
  const duration = gsap.utils.random(40, 80);
  const y = gsap.utils.random(-250, 250);
  const rotate = gsap.utils.random(-20, 20);
  const scaleXFrom = gsap.utils.random(2, 2.5);
  const scaleXTo = gsap.utils.random(1.5, 1.75);
  const scaleYFrom = gsap.utils.random(1.5, 2);
  const scaleYTo = gsap.utils.random(0.6, 0.7);
  const opacityFrom = gsap.utils.random(0.75, 0.8);
  const opacityTo = gsap.utils.random(0.85, 1);
  const ease = gsap.utils.random([
    "power2.inOut",
    "power3.inOut",
    "power4.inOut",
    "sine.inOut"]);

  tl.to($paths, {
    xPercent: -100,
    duration: duration,
    ease: "none",
    repeat: -1
  });


  tl.fromTo(
    $el,
    {
      y,
      opacity: opacityFrom,
      rotate,
      scaleY: scaleYFrom,
      scaleX: scaleXFrom,
      transformOrigin: "50% 50%"
    },

    {
      y: y * -1,
      opacity: opacityTo,
      rotate: rotate * -1,
      scaleY: scaleYTo,
      scaleX: scaleXTo,
      repeat: -1,
      yoyo: true,
      yoyoEase: ease,
      duration: duration * 0.25,
      ease: ease,
      transformOrigin: "50% 50%"
    },

    0);


  tl.seek(gsap.utils.random(10, 20));
};

gsap.utils.toArray(".g").forEach($el => Line($el));
gsap.to("svg", { opacity: 1, duration: 1 });
