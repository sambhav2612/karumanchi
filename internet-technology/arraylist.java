/**
 * A simple Java program to demonstrate ArrayList using Classes and Objects
 * @author Sambhav Jain
 */

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

class Student {
    // instance variables
    int roll_no;
    String name;

    public Student(int r, String s) {
        roll_no = r;
        name = s;
    }

    public int getRollNo() {
        return roll_no;
    }

    public String getName() {
        return name;
    }

    public void set(int r, String s) {
        roll_no = r;
        name = s;
    }
}

public class arraylist {
    public static int randInt(int min, int max) {
        return ThreadLocalRandom.current().nextInt(min, max + 1);
    }

    public static void main(String[] args) {
        ArrayList<Student> array = new ArrayList<Student>(5);
        Scanner scanner = new Scanner(System.in);
        String name;

        for (int i = 0; i < 5; ++i) {
            System.out.print("Enter a name - ");
            name = scanner.nextLine();
            // randomly generating roll numbers while taking name as input from user
            array.add(new Student(randInt(1, 43), name));
        }

        // display using foreach
        for (Student student : array) {
            System.out.println(student.getRollNo() + " " + student.getName());
        }

        // randomly remove an element in range of 5
        array.remove(randInt(0, 4));

        // add a new instance
        System.out.print("Enter a name - ");
        name = scanner.nextLine();
        array.add(new Student(randInt(1, 43), name));

        scanner.close();

        // display using foreach
        for (Student student : array) {
            System.out.println(student.getRollNo() + " " + student.getName());
        }
    }
}
