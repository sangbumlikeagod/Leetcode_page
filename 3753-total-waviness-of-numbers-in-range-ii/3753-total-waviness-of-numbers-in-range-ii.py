class DPResult:
    __slots__ = ['waviness', 'count']
    def __init__(self, waviness, count):
        self.waviness = waviness
        self.count = count


# DP = DP[digit][next][nnext]
# DP = DP[digit][next][nnext][touchLimit]
# DP = DP[digit][next][nnext][start][touchLimit]
NUM_STR = ""
dp = []

def _dp(
        d_pos : int,
        start : int,
        bback : bool,
        # 내 저장해야 위치가 어딘지는 알아야함
        my_digit : int,
        # 아무래도 필요함
        next_digit : int,
    ) -> DPResult:
    # print(f"d_pos{d_pos} handle {'0' * (d_pos - 2 )if d_pos > 2 else ""} {my_digit}_{next_digit}__ ")
    res = DPResult(0, 0)
    if d_pos == len(NUM_STR):
        res.count += 1
        # dp[d_pos][my_digit][0][1] = res
        return res

    if not bback and dp[d_pos][my_digit][next_digit][start] is not None:
        return dp[d_pos][my_digit][next_digit][start]


    # 1개에 버퍼를 준건가
    # 시작을 했으면 그 digit값에 맞춰야하고
    threshold = int(NUM_STR[d_pos])
    myceil = threshold if bback else 9
    # print(myceil)
    # 한계까지 모두 돈다 -> next_digit
    # dp[d_pos][next_digit][nnumber][start?]
    for nnumber in range(myceil + 1):
        nbback = bback and (nnumber == myceil)
        if nnumber == 0 and not start:

            you = _dp(
                d_pos + 1,
                False,
                # 빡이냐 아니냐
                nbback,
                10,
                10,
            )
            res.count += you.count
            res.waviness += you.waviness
        else:
            # 일단 보내고
            nnext_digit = my_digit if start else 10

            you = _dp(
                d_pos + 1,
                True,
                nbback,
                # next_digit,
                nnumber,
                nnext_digit,
                # ...
            )
            res.count += you.count
            res.waviness += you.waviness
            if start and next_digit != 10:
                # if my_digit < next_digit and next_digit > nnumber:
                #     res.waviness += you.count
                # elif my_digit > next_digit and next_digit < nnumber:
                #     res.waviness += you.count
                if next_digit < my_digit and my_digit > nnumber:
                    res.waviness += you.count
                elif next_digit > my_digit and my_digit < nnumber:
                    res.waviness += you.count
    if not bback:
        dp[d_pos][my_digit][next_digit][start] = res
        # print(
        #     NUM_STR,
        #     dp[d_pos][my_digit][next_digit][start].count,
        #     dp[d_pos][my_digit][next_digit][start].waviness
        # )
    return res
    
def DP(num: int):
    global dp
    global NUM_STR
    NUM_STR = str(num)
    dp = [
        [
            [
                [None] * 2
                for _ in range(11)
            ]
            for _ in range(11)
        ]
        for _ in range(16)
    ]
    # print(len(dp))
    # print(len(dp[0]))
    # print(len(dp[0][0]))
    # print(len(dp[0][0][0])))
    # print("=====" * 20)
    return _dp(0, False, True, 10, 10).waviness


class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        return DP(num2) - DP(num1 - 1)