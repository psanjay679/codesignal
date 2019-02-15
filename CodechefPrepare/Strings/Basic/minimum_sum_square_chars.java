import java.io.*;
import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Iterator;

class Main{

    static class IntCompare implements Comparator<Integer>{
        @Override
        public int compare(Integer a, Integer b){
            if (a > b){
                return -1;
            }
            else if (a < b){
                return 1;
            }
            else{
                return 0;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();
        int k = sc.nextInt();
        int MAX_CHARS = 26;

        // System.out.println("All input done. Going to proceed for result...");

        int[] frequency = new int[MAX_CHARS];
        Comparator c = new IntCompare();
        PriorityQueue<Integer> p_queue = new PriorityQueue<>(c);
        
        for (int i = 0; i < MAX_CHARS; i++){
            frequency[i] = 0;
        }

        for (int i = 0; i < s.length(); i++){

            // System.out.println("Value of diff: " + (s.charAt(i) - 'a'));
            frequency[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < MAX_CHARS; i++){
            p_queue.add(frequency[i]);
        }

        // System.out.println("*****Going to print PriorityQueue*****");
        Iterator it = p_queue.iterator();
        
        // while (it.hasNext()) {
        //     System.out.println(it.next() + " ");
        // }

        // System.out.println("Top Element: " + p_queue.peek());

        // System.out.println("****printing done*****");

        while (k > 0){
            int temp = p_queue.peek();
            p_queue.poll();
            temp = temp - 1;
            p_queue.add(temp);
            k -= 1;
        }

        int result = 0;
        
        while (!p_queue.isEmpty()){
            int temp = p_queue.peek();
            result += temp * temp;
            p_queue.poll();
        }

        System.out.println("Minimum Sum: " + result);
    }
}