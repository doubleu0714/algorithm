package com.doubleu0714.algorithm.recursion;

import java.util.Scanner;

/**
 * 피보나치 수열의 인덱스를 입력받아 해당 인덱스 번째의 피보나치 수를 찾는 프로그램.
 * 입력형태 : 6
 * 출력형태 : 8
 * 
 * 피보나치 수열의 법칙은 아래와 같다.
 * F(n) = 0 (n=0)
 * F(n) = 1 (n=1)
 * F(n) = F(n-1) + F(n-2)
 */
public class Fibonacci {
    public static void main(String... args) {
    // base exponent 형태로 값을 입력 받는다.
        int fibonacciIdx = 0;
        Fibonacci fibonacci = new Fibonacci();
        try(Scanner buf = new Scanner(System.in)) {
            while(buf.hasNext()) {
                fibonacciIdx = buf.nextInt();
                System.out.println(fibonacci.calculate(fibonacciIdx));
            }
        }
        // 입력된 값을 calpower로 호출한다.
        // 결과값을 출력한다.
    }

    /**
     * @param fibonacciIdx 피보나치 수열에서의 순번
     * @return
     * fibonacciIdx == 0 일 경우 0,
     * fibonacciIdx == 1 일 경우 1,
     * 그외의 경우 피보나치 수를 리턴한다.
     */
    public int calculate(int fibonacciIdx) {
        if(fibonacciIdx == 0) {
            return 0;
        } else if(fibonacciIdx == 1) {
            return 1;
        } else {
            return calculate(fibonacciIdx - 1) + calculate(fibonacciIdx - 2); 
        }
    }
}