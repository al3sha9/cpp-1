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
    List<int>.generate(5, (index) => index + 1),
    [],
    []
  ];

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
              setState(() {
                stacks[standIndex].insert(0, plateSize);
              });
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
}
