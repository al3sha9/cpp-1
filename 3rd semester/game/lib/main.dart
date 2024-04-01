import 'package:flutter/material.dart';

void main() {
  runApp(TowersOfHanoiApp());
}

class TowersOfHanoiApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Towers of Hanoi',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: TowersOfHanoiPage(),
    );
  }
}

class TowersOfHanoiPage extends StatefulWidget {
  @override
  _TowersOfHanoiPageState createState() => _TowersOfHanoiPageState();
}

class _TowersOfHanoiPageState extends State<TowersOfHanoiPage> {
  // Number of plates
  final int numberOfPlates = 5;

  // Stacks representing the stands
  List<List<int>> stacks = [
    List<int>.generate(
        5, (index) => 5 - index), // Initialize plates on the first stand
    [],
    [],
  ];

  // Flag to check if the game is won
  bool gameWon = false;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Towers of Hanoi'),
      ),
      body: Row(
        mainAxisAlignment: MainAxisAlignment.spaceEvenly,
        children: List.generate(3, (index) {
          return _buildStand(index);
        }),
      ),
    );
  }

  Widget _buildStand(int standIndex) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.end,
      children: List.generate(
        numberOfPlates,
        (plateIndex) {
          final plateSize = plateIndex < stacks[standIndex].length
              ? stacks[standIndex][plateIndex]
              : null;
          return DragTarget<int>(
            onAccept: (int plateSize) {
              _movePlate(standIndex, plateSize);
            },
            builder: (context, candidateData, rejectedData) {
              return Container(
                width: 100.0,
                height: 20.0 + (plateSize ?? 0) * 20.0,
                decoration: BoxDecoration(
                  color: Colors.transparent,
                  border: Border.all(color: Colors.black),
                  borderRadius: BorderRadius.circular(10.0),
                  gradient: LinearGradient(
                    colors: [Colors.red.shade300, Colors.red.shade500],
                    begin: Alignment.topCenter,
                    end: Alignment.bottomCenter,
                  ),
                ),
                child: plateSize != null
                    ? Draggable<int>(
                        data: plateSize,
                        child: Container(
                          width: 100.0,
                          height: 20.0,
                          decoration: BoxDecoration(
                            color: Colors.red.shade700,
                            borderRadius: BorderRadius.circular(10.0),
                          ),
                        ),
                        feedback: Material(
                          elevation: 8.0,
                          child: Container(
                            width: 100.0,
                            height: 20.0,
                            decoration: BoxDecoration(
                              color: Colors.red.shade700.withOpacity(0.5),
                              borderRadius: BorderRadius.circular(10.0),
                            ),
                          ),
                        ),
                        childWhenDragging: Container(),
                      )
                    : null,
              );
            },
          );
        },
      ).reversed.toList(),
    );
  }

  void _movePlate(int toStand, int plateSize) {
    setState(() {
      // Check if the game is already won
      if (!gameWon) {
        // Check if the move is valid
        if (_isValidMove(toStand, plateSize)) {
          // Remove plate from the previous stand
          for (int i = 0; i < stacks.length; i++) {
            if (stacks[i].contains(plateSize)) {
              stacks[i].remove(plateSize);
              break;
            }
          }
          // Add plate to the new stand
          stacks[toStand].insert(0, plateSize);
          // Check for win condition
          _checkWinCondition();
        }
      }
    });
  }

  bool _isValidMove(int toStand, int plateSize) {
    // If the destination stand is empty or the plate being moved is smaller
    // than the top plate on the destination stand, the move is valid
    return stacks[toStand].isEmpty || plateSize < stacks[toStand].first;
  }

  void _checkWinCondition() {
    // Check if all plates are on the last stand
    if (stacks[2].length == numberOfPlates) {
      setState(() {
        gameWon = true;
      });
      // Display a dialog indicating that the game is won
      showDialog(
        context: context,
        builder: (BuildContext context) {
          return AlertDialog(
            title: Text('Congratulations!'),
            content: Text('You won the game!'),
            actions: [
              TextButton(
                onPressed: () {
                  Navigator.of(context).pop();
                },
                child: Text('OK'),
              ),
            ],
          );
        },
      );
    }
  }
}
