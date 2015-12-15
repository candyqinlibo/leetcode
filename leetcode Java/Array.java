package pratice;

public class Array {
	private int[] a;
	private int nEle;
	
	public Array(int max){
		a = new int[max];
		nEle = 0;
	}
	
	public boolean find(int key){
		for (int j = 0; j < nEle; j++) {
			if (a[j] == key) {
				return true;
			}
		}
		return false;
	}
	
	public int BinaryFind(int key){
		int lower = 0;
		int upper = nEle-1;
		int curIn;
		while(true){
			curIn = (lower + upper)/2;
			if(a[curIn] == key){
				return curIn;
			}
			else if(lower > upper){
				return nEle;
			}
			else{
				if(a[curIn] < key){
					lower = curIn + 1;
				}
				else{
					upper = curIn - 1;
				}
			}
		}
	}
	
	public void insert(int key){
		a[nEle] = key;
		nEle++;
	}
	
	public boolean delete(int key){
		int j;
		for(j = 0;j<nEle;j++){
			if(a[j] == key){
				break;
			}
		}
		if(j == nEle){
			return false;
		}
		else{
			for(int p = j;p<nEle;p++){
				a[p] = a[p+1];
			}
			nEle--;
			return true;
		}
	}
	
	public void display(){
		for(int i = 0;i<nEle;i++){
			System.out.print(a[i] + " ");
		}
	}
	
	public int getSize(){
		return nEle;
	}
	
	public void bubblesort(){
		for(int i = 0;i<nEle-1;i++){
			for(int j = 0;j<nEle-1-i;j++){
				if(a[j] > a[j+1]){
					swap(j,j+1);
				}
			}
		}
	}
	
	public void swap(int m,int n){
		int temp = a[m];
		a[m] = a[n];
		a[n] = temp;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int maxSize = 100;
		Array array = new Array(maxSize);
		array.insert(77);
		array.insert(99);
		array.insert(44);
		array.insert(55);
		array.insert(22);
		array.insert(88);
		array.insert(11);
		array.insert(00);
		array.insert(66);
		array.insert(33);
		
		array.display();
		System.out.println();
		array.bubblesort();
		array.display();
	}

}
