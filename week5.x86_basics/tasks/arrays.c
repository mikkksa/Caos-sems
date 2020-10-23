int
main()
{
    int N;
    int *A;
    int *B;
    int *R;
    scanf("%d", &N);
    A = calloc(N, sizeof(*A));
    B = calloc(N, sizeof(*B));
    R = calloc(N, sizeof(*R));
    int i;
    for (i=0; i<N; ++i) {
        scanf("%d", &(A[i]));
    }
    for (i=0; i<N; ++i) {
        scanf("%d", &(B[i]));
    }
    summ(N, A, B, R);
    for (i=0; i<N; ++i) {
        printf("%d ", R[i]);
    }
    printf("\n");
    free(A);
    free(B);
    free(R);
}
