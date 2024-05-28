import java.io.*;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.Map;
public class P5 {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(r.readLine());
		int num = Integer.parseInt(st.nextToken());
		for(int a = 0; a< num; a++){
			st = new StringTokenizer(r.readLine());
			int len = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(r.readLine());
			String s = st.nextToken();
			pw.println(Ans(len, s));
		}
		pw.close();
	}
	public static int Ans(int len, String s){
		for(int seg = 1; seg<= len; seg++){
			HashMap<String, Integer> map = new HashMap<>();
			if(len%seg == 0){
				for(int b = 0; b< len/seg; b++){
					String put = s.substring(b*seg, (b+1) * seg);
					if(map.containsKey(put)){
						int hold = map.get(put);
						map.put(put, hold+1);
					}
					else{
						map.put(put, 1);
					}
				}
				
				int min = 2147483647;
        		for (int value : map.values()) {
           			min = Math.min(value, min);
        		}
				if(map.size()==1){return seg;}
				if(map.size()==2){
					String one = "";
					String two = "";
					boolean hi = true;
					for (Map.Entry<String, Integer> entry : map.entrySet()) {
            			String key = entry.getKey();
						if(hi){
							one = key;
							hi = false;
						}
						else{
							two = key;
						}
					}
					int dif = 0;
					for(int x = 0; x< one.length(); x++){
						if(!(one.charAt(x)+"").equals(two.charAt(x)+"")){
							dif++;
						}
					}
					if(dif == 1){
						if(min<=1){
							return seg;
						}
					}
					else{
						if(min ==0){
							return seg;
						}
					}
				}
			}
		}
		return len;
	}
}