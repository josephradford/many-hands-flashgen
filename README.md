# Many Hands Flash Generation Utility

This project contains a basic desktop app that is used to help write Arduino code for the related project
* [Many Hands PIR](https://bitbucket.org/jtradford/many-hands-pir)

## Getting started

### Prerequisites
* Qt 5.8.0
* Qt Creator 4.2.2

### Installing
* Clone the repository
* Launch flashgen/flashgen.pro in Qt Creator
* Run the code

## Running the app
The app records your timings of the 'a', 's', and 'd' keys to populate a series of structs for the related Arduino project to use, e.g.

```
flashRoutines[0].flash[0].port = 0;
flashRoutines[0].flash[0].hold = 200;
flashRoutines[0].flash[0].pause = 400;
```

All of the variables in the above example can be modified in the desktop app.

The recording can be quantised to nearest x millisecond, so that the output can be uniform if desired.

This will save you many painstaking hours trying to program in a flash routine for the Arduino project.


## Version
This will not get a full release.

## Authors
* **Joseph Radford** - *Initial work*
