let board = [
    ['', '', ''],       //3 x 3 board.
    ['', '', ''],
    ['', '', '']
  ];
  
  let w; // = width / 3;
  let h; // = height / 3;
  
  let computer = 'X'; //when the screen represents X that means computer player has make a move
  let human = 'O'; ///when the screen represents O that means human has make a move
  let currentPlayer = human;
  
  function setup() {
    createCanvas(400, 400); //canvas used to present graphics
    w = width / 3;
    h = height / 3;
    bestMove();
  }
  
  function equals3(a, b, c) {
    return a == b && b == c && a != '';
  }
  
  function checkWinner() {     //winner here has null value.
    let winner = null;
                                        //conditions to check that winner by horizontal move, vertical move. diagonal move.
    // horizontal
    for (let m = 0; m < 3; m++) {
      if (equals3(board[m][0], board[m][1], board[m][2])) {
        winner = board[m][0];
      }
    }
  
    // Vertical
    for (let m = 0; m < 3; m++) {
      if (equals3(board[0][m], board[1][m], board[2][m])) {
        winner = board[0][m];
      }
    }
  
    // Diagonal
    if (equals3(board[0][0], board[1][1], board[2][2])) {
      winner = board[0][0];
    }
    if (equals3(board[2][0], board[1][1], board[0][2])) {
      winner = board[2][0];
    }
  
    let openSpots = 0;
    for (let m = 0; m < 3; m++) {
      for (let n = 0; n < 3; n++) {
        if (board[m][n] == '') {
          openSpots++;
        }
      }
    }
  
    if (winner == null && openSpots == 0) { //if sopt has 0 value and winner value is also 0 then the game is tie 
    //on the other hand if the spot return some value and winner too return the winner 
      return 'tie';
    } else {
      return winner;
    }
  }
  
  function mousePressed() {
    if (currentPlayer == human) {
      // Human make turn
      let m = floor(mouseX / w);
      let n = floor(mouseY / h);
      // If valid turn
      if (board[m][n] == '') {
        board[m][n] = human;
        currentPlayer = computer;
        bestMove();
      }
    }
  }
  
  function draw() {
    background(255);
    strokeWeight(4);
  
    line(w, 0, w, height);
    line(w * 2, 0, w * 2, height);
    line(0, h, width, h);
    line(0, h * 2, width, h * 2);
  
    for (let n = 0; n < 3; n++) {
      for (let m = 0; m < 3; m++) {
        let x = w * m + w / 2;
        let y = h * n + h / 2;
        let spot = board[m][n];
        textSize(32);
        let r = w / 4;
        if (spot == human) {
          noFill();
          ellipse(x, y, r * 2);
        } else if (spot == computer) {
          line(x - r, y - r, x + r, y + r);
          line(x + r, y - r, x - r, y + r);
        }
      }
    }
  
    let result = checkWinner();
    if (result != null) {
      noLoop();
      let resultP = createP('');
      resultP.style('font-size', '32pt');
      if (result == 'tie') {
        resultP.html('Tie!');
      } else {
        resultP.html(`${result} wins!`);
      }
    }
  }
  
  function bestMove() {
  // computer to make its turn
  // maximizer takes first turn which has worst-case initial value =- infinity
  // Minimizer will take next turn which has worst-case initial value = +infinity.
  let bestScore = -Infinity;
  let move;
  for (let m = 0; m < 3; m++) {
    for (let n = 0; n < 3; n++) {
      // Is the spot available?
      if (board[m][n] == '') {
        board[m][n] = computer;
        let score = minimax(board, 0, false);
        board[m][n] = '';
        if (score > bestScore) {
          bestScore = score;
          move = { m, n };
        }
      }
    }
  }
  board[move.m][move.n] = computer;
  currentPlayer = human;
}

let scores = {
  X: 10,
  O: -10,
  tie: 0
};

function minimax(board, depth, isMaximizing) {
  let result = checkWinner();
  if (result !== null) {
    return scores[result];
  }
//Maxmizing function. (Maximizer will try to get the Maximum possible score.)
  if (isMaximizing) {
    let bestScore = -Infinity;
    for (let m = 0; m < 3; m++) {
      for (let n = 0; n < 3; n++) {
        // Is the spot available?
        if (board[m][n] == '') {
          board[m][n] = computer;
          let score = minimax(board, depth + 1, false);
          board[m][n] = '';
          bestScore = max(score, bestScore);  //return the max score 
        }
      }
    }
    return bestScore;
  } else {
    //Minimizing function (Minimizer will try to get the minimum possible score.)
    let bestScore = Infinity;
    for (let m = 0; m < 3; m++) {
      for (let n = 0; n < 3; n++) {
        // Is the spot available?
        if (board[m][n] == '') {
          board[m][n] = human;
          let score = minimax(board, depth + 1, true);
          board[m][n] = '';
          bestScore = min(score, bestScore);
        }
      }
    }
    return bestScore;
  }
}
