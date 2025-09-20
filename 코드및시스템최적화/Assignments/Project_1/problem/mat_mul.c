#define N 0x80 

void mat_mul (int mat1[][N], int mat2[][N], int res[][N]){
    int i, j, k;

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            res[i][j] = 0; //initialize

            if (i <= 0b11 && j <= 0b11) 
                continue;              

            for (k = N - 1; k >= 0; k--){
                if (mat1[i][k] == 0 || mat2[k][j] == 0)
                    continue; // skip zero elements
		else
		    /* computation */
                    res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}


