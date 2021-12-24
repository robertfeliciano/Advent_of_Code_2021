package day3;

import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;


public class day3 {

	public static String[] part_1(){
		String[] answer = new String[2];
		
		
		int[] num_zeros = new int[12];
		int[] num_ones = new int[12];
		
		char[] _gamma = new char[12];
		char[] _epsilon = new char[12];
		int place = 0;
		try {
			File input = new File("src/day3/input.txt");
			Scanner reader = new Scanner(input);
			while (reader.hasNextLine()) {
		        String data = reader.nextLine();
		        char[] bits = data.toCharArray();
		        for (char c : bits) {
		        	if (c == '0') {
		        		num_zeros[place++]++;
		        	}
		        	else {
		        		num_ones[place++]++;
		        	}
		        }
		        place = 0;
		    }
			reader.close();
		} catch(FileNotFoundException e) {
		      System.out.println("An error occurred.");
		      e.printStackTrace();
		}
		
		for (int i = 0; i < num_zeros.length; i++) {
			if (num_zeros[i] > num_ones[i]) {
				_gamma[i] = '0';
				_epsilon[i] = '1';
			}
			else {
				_gamma[i] = '1';
				_epsilon[i] = '0';
			}
		}
		
		StringBuilder gamma = new StringBuilder();
		StringBuilder epsilon = new StringBuilder();
		for (char c : _gamma) {
			gamma.append(c);
		}
		answer[0] = gamma.toString();
		
		for (char c : _epsilon) {
			epsilon.append(c);
		}
		answer[1] = epsilon.toString();
		
		return answer;
	}

	public static void main(String[] args) {
		String[] arr = part_1();
		int g = Integer.parseInt(arr[0], 2);
		int e = Integer.parseInt(arr[1], 2);
		System.out.println("gamma = " + g);
		System.out.println("epsilon = " + e);
		System.out.println("gamma * epsilon = " + g*e);
	}

}
