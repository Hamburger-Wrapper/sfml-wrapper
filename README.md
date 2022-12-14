# Project Documentation

## Maintainers

- **[Marty Martin](https://github.com/FancyKat)**
- **[Brent Knopp](https://github.com/bknopp71)**
- **[Nolan Meyers](https://github.com/Lil-Junko)**

## Members Responsibility

All **Push** and **Pull Request** will be done on a members personal branch.

After morning stand up, all members will then commit code that was edited and does not conflict with other members code commits. This will then be pushed to the **development** branch. After the final push to the **development** the team github manager will push to the **main** branch.

## Project Structure

```zsh
.
|-- LICENSE
|-- README.md
|-- assets
|   |-- fonts
|   |   |-- JellyBomb.ttf
|   |   `-- README.md
|   |-- images
|   |   |-- FolderArch.jpg
|   |   |-- Homepage.png
|   |   `-- README.md
|   `-- toolkit
|       `-- README.md
|-- headers
|   |-- README.md
|   |-- animation.h
|   |-- button.h
|   |-- graphBuilder.h
|   `-- particleSystem.h
|-- makefile
|-- pages
|   |-- README.md
|   |-- homepage.cpp
|   `-- menu.cpp
`-- src
    |-- animation.cpp
    |-- button.cpp
    |-- graphBuilder.cpp
    |-- main.cpp
    `-- particleSystem.cpp
```

<img src="./assets/images/Homepage.png"
alt="homepage-prototype"
style="display: block;
        margin-left: auto;
        margin-right: auto;
        width: 50%;"
title="HomePage ">

## Project Overview

This project has 3 phases which include:

1. 4 individual mini games
2. Graphical Calculator
3. Robot Wrapper

Each phase is a stand alone program of the main project.

## Contributing

### Pull Request Process

1. Ensure any install or build dependencies are removed before the end of the layer when doing a build.
2. Update the `README.md` with details of changes to the interface, this includes new environment variables, exposed ports, useful file locations and container parameters.
3. Increase the version numbers in any examples files and the `README.md` to the new version that this Pull Request would represent.
4. You may merge the Pull Request in once you have the sign-off of two other developers, or if you do not have permission to do that, you may request the second reviewer to merge it for you.
