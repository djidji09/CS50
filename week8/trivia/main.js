document.addEventListener("DOMContentLoaded", function () {
    let correct = document.querySelector(".right");
    correct.addEventListener("click", function () {
      correct.style.backgroundColor = "green";
      document.querySelector("#response1").innerHTML = "correct";
      document.querySelector("#response1").style.color = "green";
    });

    let incorrect = document.querySelectorAll(".wrong");
    for (let index = 0; index < incorrect.length; index++) {
      incorrect[index].addEventListener("click", function () {
        incorrect[index].style.backgroundColor = "red";
        document.querySelector("#response1").innerHTML = "incorrect";
        document.querySelector("#response1").style.color = "red";
      });
    }

    document.querySelector("#form2").addEventListener("submit", function (event) {
      let show = document.querySelector("#show");
      if (show.value.toLowerCase() == "the office") {
        show.style.backgroundColor = "green";
        document.querySelector("#response2").innerHTML = "Correct";
        document.querySelector("#response2").style.color = "green";
      } else {
        show.style.backgroundColor = "red";
        document.querySelector("#response2").innerHTML = "Incorrect";
        document.querySelector("#response2").style.color = "red";
      }
      event.preventDefault();
    });
  });
