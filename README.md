# Drone Stimulation System

## Overview

A project to simulate the behavior of the drone and robots. Set the pickup location and the final destination of the robot, and afterward the drone will come and pick up the robot toward their destination. Not only the transportation simulation but you will be able to decide what to do with the robot's behavior when the passenger arrived at ther destination or if the drone is too late to pickup. The Drone Stimulation System (DSS) is an intricate and comprehensive simulation framework designed for the study and analysis of drones and aerial vehicles. This system is a testament to the fusion of cutting-edge technology and innovative engineering, offering a platform to simulate, analyze, and understand the dynamics of drone operations. This document serves as a comprehensive guide to understanding, installing, and utilizing the DSS.

#### What is in this directory?
<ul>
  <li>  <code>README.md</code>
  <li>  <code>.gitignore</code>
  <li>  <code>app</code> folder, which contains:
    <ul>
      <li>  <code>graph_viewer</code> : producing graph visualization
      <li>  <code>transit_service</code> : visualization
    </ul>
  <li>  <code>libs</code> folder, which contains:
    <ul>
      <li>  <code>routing</code> : finding the paths
      <li>  <code>trainsit</code> : entities properties
    </ul>
  <li>  <code>dependencies</code>
</ul>



### Philosophy
At its core, the DSS is built around the philosophy of modular design, allowing for flexible integration of various components and subsystems. This design philosophy ensures that the system is not only robust but also adaptable to the ever-evolving landscape of drone technology.

## Key Features
- **Simulation Engine**: The heart of DSS, it simulates complex aerial dynamics, environmental interactions, and drone behaviors with high fidelity.
- **Advanced Routing and Pathfinding**: Incorporates a variety of algorithms for efficient and realistic navigation, crucial for applications in delivery, surveillance, and exploration.
- **Real-time Collision Detection**: A critical feature for ensuring safe operation in crowded or complex environments.
- **Modular Control Strategies**: Enables the implementation of diverse control algorithms, from basic manual controls to advanced autonomous systems.
- **Data Collection and Analysis**: Equipped with tools for logging flight data, sensor readings, and performance metrics for post-flight analysis.
- **Graphical Visualization**: Offers a suite of tools for visualizing simulation scenarios, drone paths, and behaviors, enhancing the understanding of flight dynamics.

## Detailed Project Structure
### `apps`
Contains executable applications and scripts for running simulations. It includes various predefined scenarios and allows users to create custom simulation environments. 

### `build`
Hosts the build scripts and resources essential for compiling the project. It includes Makefiles, configuration scripts, and other build-related tools.

### `dependencies`
Details and manages all external dependencies required by the DSS. This directory is crucial for maintaining the integrity and compatibility of the system components.

### `docs`
An extensive collection of documentation files, including HTML pages detailing each class, interface, and module. This directory is a valuable resource for understanding the system's internals.

### `libs`
Core libraries and modules that form the backbone of the DSS. These libraries are utilized across various components of the system.

### `pics`
Contains images, diagrams, and visual aids related to the project. It offers visual context and enhances the understanding of the system architecture and workflow.

### `src`
The main source code repository, subdivided into various directories:

#### `routing`
Houses the logic for pathfinding and routing algorithms. This directory is key for scenarios involving navigation and trajectory planning.

#### `simulation`
Contains the core logic and algorithms for simulating drone behaviors and interactions. It includes models for drone dynamics, environmental factors, and sensor simulations.

#### `transit`
Dedicated to code related to transit and vehicle simulation. It extends the capabilities of the DSS to encompass a broader range of vehicular simulations beyond aerial drones.

#### `util`
A collection of utility functions and common tools used throughout the project. This directory improves code reusability and maintains consistency across the system.

### In-Depth Documentation
The `docs` directory provides exhaustive documentation covering the classes, interfaces, and modules integral to the DSS. This includes:

- **Class Diagrams**: Visual representations of the system's class hierarchy and relationships.
- **Method Descriptions**: Detailed explanations of each method, including parameters, return types, and usage examples.
- **Module Overviews**: High-level descriptions of each module, outlining its role and functionality within the system.

## Installation Guide
To get the DSS up and running on your system, follow these steps:

### Prerequisites
- Ensure that your system meets the minimum hardware and software requirements (listed separately).
- Install Git to clone the repository.

### Step-by-Step Installation
1. **Clone the Repository**: Use Git to clone the DSS repository to your desired location.
2. **Install Dependencies**: Navigate to the `dependencies` directory. Follow the detailed instructions to install all necessary dependencies, ensuring compatibility and proper functioning.


## Getting Started

Here is a quick overview of how to run the visualization (If you are using ssh, navigate to ssh category below):

    ```bash
    # Go to the project directory
    cd /path/to/repo/project
    
    # Build the project
    make -j
    
    # Run the project (./build/web-app <port> <web folder>)
    ./build/bin/transit_service 8081 apps/transit_service/web/
    ```
    
Navigate to http://127.0.0.1:8081 and you should see a visualization.

Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.

Below are instructions that detail how to build and run in several different environments.  

## Getting Started using SSH onto CSE Lab machines

1. SSH into a CSE Lab Machine using **port forwarding** for the UI

   **Note:** If port `8081` is not available, choose a different port (e.g. 8082, 8083, etc...)

    ```bash
    ssh -L 8081:127.0.0.1:8081 x500@csel-xxxx.cselabs.umn.edu
    ```
    
    Example:
    ```bash
    ssh -L 8081:127.0.0.1:8081 kaung006@csel-kh1250-05.cselabs.umn.edu
    ```

2. Compile the project (within ssh session)

    ```bash
    cd /path/to/repo/project
    make -j
    ```
    
 2. Run project (within ssh session)

    ```bash
    ./build/bin/transit_service 8081 apps/transit_service/web/
    ```

5. Navigate to http://127.0.0.1:8081 and you should see a visualization.

6. Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.

# Simulation

## Schedule
You will be able to schedule the robots for a ride in this page http://127.0.0.1:8081/schedule.html. 

Type passenger name, select start and end destination, and press `Schedule Trip` button to schedule a trip. 

Now go to 3D Visualization page and select the view of the entities on top right corner.

## 3D Visualization
You will be able to watch the simulation of the drone and the passenger here http://127.0.0.1:8081.

On top right corner, you can change your camera view into locking the entities.

## Running the Simulations
To launch and run simulations in the DSS, follow these instructions:

1. **Compiling the Project**: Use the provided `Makefile` in the `build` directory to compile the project. This process involves compiling source files and linking libraries.
2. **Executing the Application**: Once compiled, run the application from the `apps` directory. The `README_Project.md` file contains detailed instructions on command-line arguments, configuration settings, and how to initiate different simulation scenarios.

## Customization and Extension
The DSS is designed for extensibility and customization. Users can enhance the system by:

- **Adding Control Strategies**: Implement new control algorithms in the `control` submodule within `src`. This can range from simple PID controllers to complex AI-driven systems.
- **Developing Routing Algorithms**: Expand the `routing` directory with additional pathfinding algorithms, improving the system's navigation capabilities.
- **Creating Simulation Scenarios**: Modify or add scripts in the `apps` directory to craft custom simulation environments, tailored to specific research or testing needs.

## Data Collection and Analysis
One of the key features of DSS is its data collection and analysis capabilities. This system can log various types of data during simulations, including:

- **Flight Data**: Records all aspects of the drone's flight, such as altitude, speed, and trajectory.
- **Sensor Data**: Gathers data from simulated sensors, providing insights into the drone's interaction with its environment.
- **Performance Metrics**: Logs system performance, useful for evaluating the efficiency and effectiveness of different algorithms and strategies.

The data collected can be analyzed post-simulation using the tools provided in the `analysis` directory. This enables users to derive meaningful insights and make informed decisions regarding drone operation and strategy optimization.

## Graphical Visualization
The DSS provides a comprehensive suite of graphical tools for visualizing simulation data. These tools are crucial for understanding complex flight dynamics and behaviors. They include:

- **Trajectory Visualization**: Displays the flight path of the drone, highlighting key navigational points and maneuvers.
- **Behavioral Analysis**: Visualizes the decision-making process of the drone, especially in scenarios involving autonomous control.
- **Environmental Interaction**: Shows how the drone interacts with simulated environmental elements, such as obstacles, weather conditions, and terrain.

These visualization tools are not only essential for analysis but also serve as an excellent educational resource for those looking to understand drone dynamics better.

## Course Information
This project has been developed as part of the coursework for CSCI3081W Program Design and Development Fall 2022. Principles of programming design/analysis. Concepts in software development. Uses a programming project to illustrate key ideas in program design/development, data structures, debugging, files, I/O, testing, and coding standards. Credit to Keyang Xuan, Chenyi Yang, Felix Su and Ke Wang. 
