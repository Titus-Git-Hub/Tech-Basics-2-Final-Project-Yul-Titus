# Step-by-Step Instruction

The following section describes the complete process of building our Arduino-based Stranger Things alphabet light wall. The guide is structured in clearly defined phases to ensure a logical workflow. From initial preparation (1) and testing (2) to assembling the full prototype (3).


## (1) Preparation
Before assembling the full system, we focused on testing components and preparing the wiring structure.

<details>
<summary>Show more</summary>

### 1.1 Testing the Jumper Wires
We began by testing the male-to-female jumper wires using a simple circuit on a breadboard. This step ensured:
* All wires were functional
* There were no loose or defective connections
* The Arduino board correctly powered and addressed connected components
At this stage, we worked with a minimal setup (a single LED and resistor) to verify that signals were transmitted correctly.

<img src="https://github.com/user-attachments/assets/07726b4a-8c1c-405d-be81-78b7245afe4b" width="400">
<img src="https://github.com/user-attachments/assets/131c18d1-944b-4c8a-b40d-de8d81de0ef5" width="400">


### 1.2 Organizing and Labeling the Wires
Since the final project includes many individual LED connections (one for each letter of the alphabet), proper organization was essential.
We:
* Grouped the jumper wires logically
* Secured related wires together using tape
* Labeled each wire with its corresponding alphabet letter
This significantly reduced confusion later in the assembly process and made debugging much easier.

<img src="https://github.com/user-attachments/assets/2694089c-385f-4749-b80f-a97ce64c54ec" width="400">
<img src="https://github.com/user-attachments/assets/ec86cba5-d107-423b-ab94-9d18cd2a2861" width="400">

</details>

## (2) Testing
Once the basic preparation was complete, we moved on to building and testing the core circuit logic.

<details>
<summary>Show more</summary>

### 2.1 Connecting the Breadboards and Shift Register
We connected the two breadboards and integrated the shift register into the circuit.
At this stage:
* The LEDs were not yet installed
* The focus was on verifying correct wiring of the power supply, ground connections, and data pins
* The shift register was connected to the Arduino to expand the number of usable output pins
Careful wiring here was critical, as small mistakes could affect the entire system later.

<img src="https://github.com/user-attachments/assets/6aed19d2-ca46-4fcd-a6a0-acf29eb45a7b" width="400">
<img src="https://github.com/user-attachments/assets/ed5289e3-700b-4135-8759-7d3643f8dbd0" width="400">

### 2.2 Uploading the Code and Testing Individual LEDs
After completing the wiring, we uploaded the [Arduino code](../Code/TBD) to the board + connected and tested selected LEDs.
The purpose of this step was to:
* Verify communication between Arduino and shift register
* Test whether outputs were triggered correctly or any wiring errors were present
* Ensure that the programmed letter logic worked as expected
We performed initial test runs using simple output sequences. If issues occurred, we revisited the wiring and labeling from the preparation phase.

<img src="https://github.com/user-attachments/assets/eb1cf93b-427c-4824-ae93-f506c0b48984" width="400">
<img src="https://github.com/user-attachments/assets/fc85b4b9-afa3-401c-bed8-2d9f44693a82" width="400">

</details>

## (3) First Full Assembly
After successful functional testing, we proceeded to assemble the complete light wall prototype.

<details>
<summary>Show more</summary>

### 3.1 Determining the Correct Letter Order
Before permanently installing the LEDs, we carefully arranged them in alphabetical order.
This step included:
* Verifying spacing between letters
* Ensuring visual alignment
* Planning cable routing to avoid tangling
Proper planning here improved the final appearance and stability of the wall.

<img src="https://github.com/user-attachments/assets/0e8e5604-464c-46df-86ce-107982b387f7" width="400">
<img src="https://github.com/user-attachments/assets/0e420154-b09f-44ff-96e7-0fe81b924bb7" width="400">

### 3.2 Installing and Mounting All LEDs
We then connected all LEDs to their designated positions on the breadboards.
We used a self-made mounting tool to hold the LEDs in place.
At this stage, the system visually resembled the final product for the first time.

<img src="https://github.com/user-attachments/assets/04495f6b-8fe3-43b4-a4bd-2afd21a45638" width="800">

### 3.3 Final Functional Test
Once everything was installed, we conducted a full system test.
We verified:
* Correct letter activation
* Reliable input detection
* Overall responsiveness of the system

<img src="https://github.com/user-attachments/assets/8c2b609f-fe6a-4066-a4f8-7dcd2a30a093" width="800">

</details>

## Interim Result
At this stage, we had completed a fully functional prototype of our Stranger Things alphabet light wall.
While the system worked reliably from a technical perspective, we identified several areas where the overall user experience could be improved. These observations motivated the final refinements described in the following section.

## (4) Final Additions
After successfully completing the working prototype, we implemented several final improvements to enhance usability and overall interaction quality.

<details> 
<summary>Show more</summary>

### 4.1 Changing the Input Method
During testing, we encountered recurring issues with the 4x4 matrix keypad module.  Input was occasionally not recognized correctly, which negatively impacted reliability and caused disruptions in the interaction flow.
Since we had already gained experience working with LCD displays and joystick modules, we decided to redesign the input system entirely. The new concept uses:
* A 1602 I2C LCD display to visualize the alphabet
* A joystick module for navigation and letter selection

This solution provided a significantly more intuitive and stable input method. Users can now scroll through the alphabet and select letters in a clear and controlled way, improving both reliability and overall user experience.

The updated setup looks as follows and matched our original vision much more closely in terms of both functionality and interaction design.: 

<img src="https://github.com/user-attachments/assets/5c4d908c-8466-4abc-9530-1010e017db66" width="400">
<img src="https://github.com/user-attachments/assets/a305855b-92d4-4ef5-9dcd-c40568910dad" width="400">

### 4.2 Sound Addition
As a final enhancement, we integrated a buzzer into the system to provide acoustic feedback.

Each letter activation is now accompanied by a sound signal, creating a stronger interactive experience. 

Additionally, during the “chaos mode,” the buzzer generates dynamic sound patterns to complement the visual effects and create a more dramatic atmosphere, which is inspired by the actual szene from the series.

The integration of the buzzer was technically straightforward and required only minor adjustments to the existing code and wiring.

The final setup including sound implementation:

<img src="https://github.com/user-attachments/assets/9ba1333f-8bde-45bc-b1b7-aac3844a0d80" width="400">
<img src="https://github.com/user-attachments/assets/11a8a59a-7675-4991-a044-14c4b09acda6" width="400">

</details>

## Result
With all improvements implemented, we successfully completed the updated version of our prototype.

The system now operates reliably, provides clear and intuitive input handling, and delivers both visual and acoustic feedback for an engaging user experience.

The final step involves aesthetic customization and decoration to closely replicate the appearance of the original wall from the series. This phase focuses purely on visual design and presentation and is documented separately under [aesthetic customization and decoration](../Decoration/TBD).

