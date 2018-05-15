package com.doubleu0714.algorithm.recursion;

import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        int inputValue = 0;
        try(Scanner buf = new Scanner(System.in)) {
            inputValue = buf.nextInt();
        }
        Factorial factorial = new Factorial();
        int factorialNumber = factorial.factorial(inputValue);
        System.out.println(inputValue + "! = " + factorialNumber);
    }

    public int factorial(int i) {
        if(i <= 1) {
            return 1;
        } else {
            return i * factorial(i - 1);
        }
    }
}