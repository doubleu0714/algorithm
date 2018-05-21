package com.doubleu0714.algorithm.recursion;

import java.util.Scanner;
/**
 * 입력받은 문자열 한라인을 재귀호출로 출력하는 프로그램
 */
public class PrintString {
    public static void main(String... args) {
        try(Scanner scanner = new Scanner(System.in)) {
            PrintString printString = new PrintString();
            while(true) {
                String inputValue = scanner.nextLine();

                if("exit".equals(inputValue)) break;

                printString.calculate(inputValue);
                System.out.println();
            }
        }
        System.out.println("exit");
    }

    /**
     * 입력받은 문자열의 첫번째 char를 출력하고 출력한 첫번째 문자열을 제외한 값을 재귀로 호출한다.
     * @param value 문자열
     */
    public void calculate(String value) {
        if(value.length() > 0) {
            System.out.print(value.charAt(0));
            calculate(value.substring(1));
        }
    }
}