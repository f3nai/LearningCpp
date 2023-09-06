#include <iostream>

using string = std::string;
// cant be arsed to use std::string when i can use string instead ;)

class classroom{
    // we make class for classroom since its more easier
private:
    // here we keep our variables, we can interact with them in our functions that are public
    int StudentAmount = 0;
    string ClassName = "undefined";
    // leaving it undefined cause theres a function where you can set or change the name
public:
    int GetStudentAmount() {
        return this->StudentAmount;
        // returns the student amount when called, int
    }

    string GetClassName(){
        return this->ClassName;
        // returns the class name when called, std::string / string
    }

    void SetStudents(int input) {
        this->StudentAmount = input;
        // sets the StudentAmount int value to input argument
    }

    void SetName(string input) {
        this->ClassName = input;
        // sets the ClassName string value to input argument
    }
};

void LoadList(int amount){
    // this is the function which has the loop to 'query' the students :)
    for (int i = 1; i <= amount; i++) {
        // we set i (index) as 1, because if we set it to 0 there will be for example x + 1 amount of students since we include 0 too
        if (i == amount) {
            // if the current index number is the final number (amount argument) we end it with something different from normally how we would end
            std::cout << i << " | Finished loading! total of " << amount << " students were queried.";
        } else {
            // and this is for regulars, we don't use str::endl since we want for them to be next to eachother like 1-2-3-4-, etc..
            std::cout << i << "-";
        }
    }
}

int main() {
    // the main function we will be running,
    const bool CanLoad = true;
    // the value that determines if we can run multiple times
    classroom Classroom1, Classroom2, Classroom3;
    // we create the classrooms using the class at the top of the file!

    Classroom1.SetStudents(10);
    Classroom2.SetStudents(20);
    Classroom3.SetStudents(30);

    // we set each classes student amount, made them different for obvious purposes and we put numbers in there only

    Classroom1.SetName("Classroom1");
    Classroom2.SetName("Classroom2");
    Classroom3.SetName("Classroom3");

    // same thing with set students but with class name which is a string instead of an int

    do{
        int classroom;
        // declare our classroom input variable
        std::cout << "Enter class you'd like to load";
        // print enter which class
        std::cin >> classroom;
        // capture the user input and cast it to the classroom int variable

        switch(classroom) { // switch() is better than if() in these kinds of cases I learnt today
            case 1:
                // if classroom input is 1 we load classroom1
                if (Classroom1.GetClassName() == "Classroom1") {
                    LoadList(Classroom1.GetStudentAmount());
                    // call the function that queries the students
                    break;
                }
            case 2:
                // if classroom input is 2 we load classroom2
                if (Classroom2.GetClassName() == "Classroom2") {
                    LoadList(Classroom2.GetStudentAmount());
                    // call the function that queries the students
                    break;
                }
            case 3:
                // if classroom input is 3 we load classroom3
                if (Classroom3.GetClassName() == "Classroom3") {
                    LoadList(Classroom3.GetStudentAmount());
                    // call the function that queries the students
                    break;
                }
            default:
                // and if we don't find any cases matching to 1,2 or 3 we run this section of the code block
                std::cout << "Invalid class!";
                break;
        }

    } while(CanLoad); // we keep looping this code if CanLoad is true, otherwise it's single use only!

    return 0;
}
