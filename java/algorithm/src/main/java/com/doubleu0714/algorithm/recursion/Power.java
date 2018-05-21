/**
 * 밑수와 지수를 입력 받아 recursion으로 계산하는 프로그램
 * 밑수는 정수, 지수는 양의정수만 입력이 가능하다.
 * 입력 형태 : 밑수 지수 (ex 2 3)
 * 출력 형태 : 결과 (ex 8)
 */
package com.doubleu0714.algorithm.recursion;

import java.util.Scanner;

public class Power {

    public static void main(String... args) {
        // base exponent 형태로 값을 입력 받는다.
        int base = 0;
        int exponent = 0;
        Power power = new Power();
        try(Scanner buf = new Scanner(System.in)) {
            while(buf.hasNext()) {
                base = buf.nextInt();
                exponent = buf.nextInt();
                System.out.println("base : " + base + ", exponent : " + exponent);
                System.out.println(power.calPower(base, exponent));
            }
        }
        // 입력된 값을 calpower로 호출한다.
        // 결과값을 출력한다.
    }
    
    /**
     * 지수계산인 n^m 형태는 n*n^(m-1)과 동일함
     * 위의 원리에 따라서 recursion으로 호출 할 수 있도록 구현
     */
    public int calPower(int base, int exponent) {
        // exponent값이 0보다 작으면 recursion을 종료 : base case
        if(exponent < 1) {
            return 1;
        } else { // exponent값이 0보다 크거나 같으면 recursion 호출 : recursion case
            return base * calPower(base, exponent - 1);
        }
    }
}