package com.doubleu0714.algorithm.recursion;

import java.util.Scanner;

/**
 * 입력값의 문자열을 역순으로 출력하는 프로그램
 */
public class PrintStringDesc {
    public static void main(String... args) {
        try(Scanner scanner = new Scanner(System.in)) {
            PrintStringDesc printStringDesc = new PrintStringDesc();
            while(true) {
                String inputValue = scanner.nextLine();

                if("exit".equals(inputValue)) break;

                printStringDesc.calculate(inputValue);
                System.out.println();
            }
        }
        System.out.println("exit");
    }

    /**
     * 입력받은 문자열의 마지막 char를 출력하고 출력한 출렬된 문자열을 제외한 값을 재귀로 호출한다.
     * @param value 문자열
     */
    public void calculate(String value) {
        if(value.length() > 0) {
            System.out.print(value.charAt(value.length() - 1));
            calculate(value.substring(0, value.length() - 1));
        }
    }
}