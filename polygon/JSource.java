import java.io.*;
import java.util.*;
 
public class Main {
 
    public static void main(String[] args) throws FileNotFoundException {
        fast cin = new fast();
        int n = cin.nextInt();
        long k = cin.nextLong();
        System.out.println("YES");
        for (int i = 0; i < n; i++){
		    for (int j = 0; j < n; j++){
		    	if (i == j)
		    		System.out.print(k + " ");
		    	else
		    		System.out.print("0 ");
		    }
		        System.out.println();
        }
 
    }
    public static class fast {
        BufferedReader br;
        StringTokenizer st;
 
        public fast() throws FileNotFoundException {
            br = new BufferedReader(new FileReader("Brothers.in"));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        double nextFloat() {
            return Float.parseFloat(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
 