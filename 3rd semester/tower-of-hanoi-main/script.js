var time = null;
var move_it;
var increase_movement = 1;
var sp = 0.1;

var stack;

var tower = [{}, {}, {}, {}, {}];

var top_position, left_position, elements;

window.onload = function () {
    top_position = [];
    left_position = [];
    elements = [disk0, disk1, disk2, disk3, disk4];
    for (var i = 0; i < 5; i++) {
        top_position[i] = elements[i].style.top;
        left_position[i] = elements[i].style.left;
    }
}

function run_hanoi() {
    clearInterval(time);

    for (var i = 0; i < 5; i++) {
        elements[i].style.top = top_position[i];
        elements[i].style.left = left_position[i];
    }

    tower[0].disks = ['disk0', 'disk1', 'disk2', 'disk3', 'disk4'];
    tower[1].disks = [];
    tower[2].disks = [];
    tower[3].disks = [];
    tower[4].disks = [];

    tower[0].disks.pop();
    tower[0].disks.pop();
    disk3.style.display = "none";
    disk4.style.display = "none";

    stack = [];

    disk_moving(3, 0, 2, 1);

    disk_moving_single();
}



function disk_moving(count, from, to, via) {
    if (count == 0) return;

    disk_moving(count - 1, from, via, to);

    stack.push([from, to]);
    disk_moving(count - 1, via, to, from);
}

function disk_moving_single() {
    if (stack.length == 0) return;

    var parameters = stack.shift();
    var fromTower = parameters[0];
    var toTower = parameters[1];

    var disk = document.getElementById(tower[fromTower].disks.pop());
    console.log(disk);

    move_it = {
        disk: disk,
        fromTower: fromTower,
        toTower: toTower,
        currentPosition: "top",
        direction: -1,
        movementState: "up",
        endPosition: 60
    }

    time = setInterval(animation, sp);
}

function animation() {
    var disk = move_it.disk;
    var direction = move_it.direction;

    var currentPosition = parseInt(disk[(move_it.currentPosition == "left") ? "offsetLeft" : "offsetTop"]);

    if (((direction == 1) && (currentPosition >= move_it.endPosition)) || ((direction == -1) && (currentPosition <= move_it.endPosition))) {
        if (move_it.movementState == "up") {
            move_it.movementState = "horizontal";
            move_it.currentPosition = "left";
            move_it.direction = 1;
            if (move_it.fromTower > move_it.toTower) move_it.direction = -1;
            var destinationTower = document.getElementById("bar" + move_it.toTower);
            move_it.endPosition = destinationTower.offsetLeft - Math.floor(disk.offsetWidth / 2) + 15;
            return;
        }

        else if (move_it.movementState == "horizontal") {
            move_it.movementState = "down";
            move_it.currentPosition = "top";
            move_it.direction = 1;
            move_it.endPosition = document.getElementById("bottombar").offsetTop - (tower[move_it.toTower].disks.length + 1) * disk.offsetHeight;
            return;
        }

        else {
            clearInterval(time);
            tower[move_it.toTower].disks.push(disk.id);
            disk_moving_single();
            return;
        }
    }


    currentPosition = currentPosition + direction * increase_movement;
    disk.style[move_it.currentPosition] = currentPosition + "px";

    if (move_it.movementState == "up") {
        var originTower = document.getElementById("bar" + move_it.fromTower);
        if (disk.offsetTop < originTower.offsetTop) {
            var insideImgHeight = disk.getElementsByClassName("insideImg")[0].offsetHeight;
            if (insideImgHeight > 0) disk.getElementsByClassName("insideImg")[0].style.height = insideImgHeight - increase_movement + "px";
        }
    }

    if (move_it.movementState == "down") {
        var destinationTower = document.getElementById("bar" + move_it.toTower);
        if (disk.offsetTop > destinationTower.offsetTop) {
            var insideImgHeight = disk.getElementsByClassName("insideImg")[0].offsetHeight;
            if (insideImgHeight < 14) disk.getElementsByClassName("insideImg")[0].style.height = insideImgHeight + increase_movement + "px";
        }
    }

}
