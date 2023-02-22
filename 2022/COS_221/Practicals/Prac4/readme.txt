This project was compiled using openjdk-11 and thus, a version of the same or later release must be used to run it.
Github repo:- https://github.com/dylankapnias/COS221_Prac4

### The following steps assume that you are in the root folder of the project i.e., prac04/
- To run this project one will need the correct environment variables set,
  if on linux, you can just go into the provided .env_var_set file and change the information accordingly,
  then in the terminal run the command 'source .env_var_set'.

- Once the environment variables have been set, the project can be run by using the following command:
  'java -cp prac04-1.0-SNAPSHOT-shaded.jar za.ac.up.cs.cos221.App'

- Alternatively, the project can be compiled and run using the following command:
  'mvn clean compile exec:java -Dexec.mainClass="za.ac.up.cs.cos221.App"'
