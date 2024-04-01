
var timer = null;
var moveInfo;
var moveIncrement = 1;
var speed = 0.1;

var callStack;

var towerInfo = [{}, {}, {}, {}, {}];

var diskPositionsTop, diskPositionsLeft, diskElements;

window.onload = function () {
    diskPositionsTop = [];
    diskPositionsLeft = [];
    diskElements = [disk0, disk1, disk2, disk3, disk4];
    for (var i = 0; i < 5; i++) {
        diskPositionsTop[i] = diskElements[i].style.top;
        diskPositionsLeft[i] = diskElements[i].style.left;
    }
}

function executeHanoi() {
    clearInterval(timer);

    for (var i = 0; i < 5; i++) {
        diskElements[i].style.top = diskPositionsTop[i];
        diskElements[i].style.left = diskPositionsLeft[i];
    }

    towerInfo[0].disks = ['disk0', 'disk1', 'disk2', 'disk3', 'disk4'];
    towerInfo[1].disks = [];
    towerInfo[2].disks = [];
    towerInfo[3].disks = [];
    towerInfo[4].disks = [];

    towerInfo[0].disks.pop();
    towerInfo[0].disks.pop();
    disk3.style.display = "none";
    disk4.style.display = "none";

    callStack = [];

    moveDisks(3, 0, 2, 1);

    moveSingleDisk();
}



function moveDisks(count, from, to, via) {
    if (count == 0) return;

    moveDisks(count - 1, from, via, to);

    callStack.push([from, to]);
    moveDisks(count - 1, via, to, from);
}

function moveSingleDisk() {
    if (callStack.length == 0) return;

    var parameters = callStack.shift();
    var fromTower = parameters[0];
    var toTower = parameters[1];

    var disk = document.getElementById(towerInfo[fromTower].disks.pop());
    console.log(disk);

    moveInfo = {
        disk: disk,
        fromTower: fromTower,
        toTower: toTower,
        currentPosition: "top",
        direction: -1,
        movementState: "up",
        endPosition: 60
    }

    timer = setInterval(animateMove, speed);
}

function animateMove() {
    var disk = moveInfo.disk;
    var direction = moveInfo.direction;

    var currentPosition = parseInt(disk[(moveInfo.currentPosition == "left") ? "offsetLeft" : "offsetTop"]);

    if (((direction == 1) && (currentPosition >= moveInfo.endPosition)) || ((direction == -1) && (currentPosition <= moveInfo.endPosition))) {
        if (moveInfo.movementState == "up") {
            moveInfo.movementState = "horizontal";
            moveInfo.currentPosition = "left";
            moveInfo.direction = 1;
            if (moveInfo.fromTower > moveInfo.toTower) moveInfo.direction = -1;
            var destinationTower = document.getElementById("bar" + moveInfo.toTower);
            moveInfo.endPosition = destinationTower.offsetLeft - Math.floor(disk.offsetWidth / 2) + 15;
            return;
        }

        else if (moveInfo.movementState == "horizontal") {
            moveInfo.movementState = "down";
            moveInfo.currentPosition = "top";
            moveInfo.direction = 1;
            moveInfo.endPosition = document.getElementById("bottombar").offsetTop - (towerInfo[moveInfo.toTower].disks.length + 1) * disk.offsetHeight;
            return;
        }

        else {
            clearInterval(timer);
            towerInfo[moveInfo.toTower].disks.push(disk.id);
            moveSingleDisk();
            return;
        }
    }


    currentPosition = currentPosition + direction * moveIncrement;
    disk.style[moveInfo.currentPosition] = currentPosition + "px";

    if (moveInfo.movementState == "up") {
        var originTower = document.getElementById("bar" + moveInfo.fromTower);
        if (disk.offsetTop < originTower.offsetTop) {
            var insideImgHeight = disk.getElementsByClassName("insideImg")[0].offsetHeight;
            if (insideImgHeight > 0) disk.getElementsByClassName("insideImg")[0].style.height = insideImgHeight - moveIncrement + "px";
        }
    }

    if (moveInfo.movementState == "down") {
        var destinationTower = document.getElementById("bar" + moveInfo.toTower);
        if (disk.offsetTop > destinationTower.offsetTop) {
            var insideImgHeight = disk.getElementsByClassName("insideImg")[0].offsetHeight;
            if (insideImgHeight < 14) disk.getElementsByClassName("insideImg")[0].style.height = insideImgHeight + moveIncrement + "px";
        }
    }

}
