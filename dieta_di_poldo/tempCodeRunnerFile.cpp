int dieta_poldo(int n, int* numbers){
	if (n==1 || n==0){
		return 1;
	}else{
		if(numbers[n-1] < numbers[n-2]){
			return max(dieta_poldo(n-1, numbers), dieta_poldo(n-2, numbers));
		}else{
			return 1 + dieta_poldo(n-1, numbers);			
		}
	}
}