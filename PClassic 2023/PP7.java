import java.io.*;
import java.util.StringTokenizer;
import java.util.ArrayList;
public class PP7 {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(r.readLine());

		int len = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(r.readLine());

		ArrayList<Integer> al = new ArrayList<>();

		for(int a = 0; a< len; a++){
			al.add(Integer.parseInt(st.nextToken()));
		}
		ArrayList<Integer> index = new ArrayList<>();

		if(al.size()>1){
			if(al.get(0)>= al.get(1)){
				index.add(0);
			}
		}
		for(int b = 1; b< al.size()-1; b++){
			if((al.get(b) > al.get(b-1) && al.get(b) >= al.get(b+1))
			&& al.get(b-1) < al.get(b+1) ){
				index.add(b);
			}
		}

		int max = -1;
		int ans = 0;
		while(! index.isEmpty()){
			int toRemove = index.get(0);
			ArrayList<Integer> copy = new ArrayList<>(al);
			copy.remove(toRemove);
			int holder = 1;

			int curMax = copy.get(0);
			for(int a = 1; a < copy.size(); a++){
				if(curMax<copy.get(a)){
					holder++;
				}
				curMax = Math.max(copy.get(a), curMax);
			}
			if(max<holder){
				max = holder;
				ans = toRemove;
			}
			index.remove(0);
		}

		pw.print(ans+1);
		
		pw.close();
	}
}