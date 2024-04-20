class Solution:
    def asteroidCollision(self, asteroids) -> List[int]:
        count = 0
        i = 0 
        size = len(asteroids)
        while True:
            if i + 1 == size - count:
                return asteroids

            if i == -1:
                i = 0 
            if asteroids[i]*asteroids[i+1]<0 and asteroids[i] > asteroids[i+1]:
                count += 1
                if asteroids[i] + asteroids[i+1] > 0:
                    asteroids.pop(i+1)
                    continue
                elif asteroids[i] + asteroids[i+1] == 0:
                    count += 1
                    # 0일떄는 카운트를 두번해줘야한다는걸 까먹음
                    asteroids.pop(i)
                    asteroids.pop(i)
                    i -= 1 
                else: 

                    asteroids.pop(i)
                    i -= 1
                    continue
            else:
                i += 1
        
                    