long long maximumScore(int** grid, int gridSize, int* gridColSize) {
    int n = gridColSize[0];
    if (n == 1) {
        return 0;
    }

    long long*** dp = (long long***)malloc(n * sizeof(long long**));
    for (int i = 0; i < n; i++) {
        dp[i] = (long long**)malloc((n + 1) * sizeof(long long*));
        for (int j = 0; j <= n; j++) {
            dp[i][j] = (long long*)calloc(n + 1, sizeof(long long));
        }
    }

    long long** prevMax = (long long**)malloc((n + 1) * sizeof(long long*));
    for (int i = 0; i <= n; i++) {
        prevMax[i] = (long long*)calloc(n + 1, sizeof(long long));
    }
    long long** prevSuffixMax =
        (long long**)malloc((n + 1) * sizeof(long long*));
    for (int i = 0; i <= n; i++) {
        prevSuffixMax[i] = (long long*)calloc(n + 1, sizeof(long long));
    }
    long long** colSum = (long long**)malloc(n * sizeof(long long*));
    for (int c = 0; c < n; c++) {
        colSum[c] = (long long*)calloc(n + 1, sizeof(long long));
        for (int r = 1; r <= n; r++) {
            colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int currH = 0; currH <= n; currH++) {
            for (int prevH = 0; prevH <= n; prevH++) {
                if (currH <= prevH) {
                    long long extraScore = colSum[i][prevH] - colSum[i][currH];
                    dp[i][currH][prevH] =
                        fmax(dp[i][currH][prevH],
                             prevSuffixMax[prevH][0] + extraScore);
                } else {
                    long long extraScore =
                        colSum[i - 1][currH] - colSum[i - 1][prevH];
                    dp[i][currH][prevH] =
                        fmax(dp[i][currH][prevH],
                             fmax(prevSuffixMax[prevH][currH],
                                  prevMax[prevH][currH] + extraScore));
                }
            }
        }

        for (int currH = 0; currH <= n; currH++) {
            prevMax[currH][0] = dp[i][currH][0];
            for (int prevH = 1; prevH <= n; prevH++) {
                long long penalty =
                    (prevH > currH) ? (colSum[i][prevH] - colSum[i][currH]) : 0;
                prevMax[currH][prevH] = fmax(prevMax[currH][prevH - 1],
                                             dp[i][currH][prevH] - penalty);
            }

            prevSuffixMax[currH][n] = dp[i][currH][n];
            for (int prevH = n - 1; prevH >= 0; prevH--) {
                prevSuffixMax[currH][prevH] =
                    fmax(prevSuffixMax[currH][prevH + 1], dp[i][currH][prevH]);
            }
        }
    }

    long long ans = 0;
    for (int k = 0; k <= n; k++) {
        ans = fmax(ans, fmax(dp[n - 1][n][k], dp[n - 1][0][k]));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);

    for (int i = 0; i <= n; i++) {
        free(prevMax[i]);
        free(prevSuffixMax[i]);
    }
    free(prevMax);
    free(prevSuffixMax);

    for (int c = 0; c < n; c++) {
        free(colSum[c]);
    }
    free(colSum);

    return ans;
}