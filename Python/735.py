class Solution:
    def asteroidCollision(self, asteroids) -> List[int]:
        count = 0
        i = 0 
        size = len(asteroids)
        while i >= 0:
            if i + 1 == size - count:
                return asteroids
            if asteroids[i]*asteroids[i+1]<0 and asteroids[i] > asteroids[i+1]:
                count += 1
                if asteroids[i]+asteroids[i+1] > 0:
                    asteroids.pop(i+1)
                    continue
                elif asteroids[i] + asteroids[i+1] == 0:
                    asteroids.pop(i)
                    asteroids.pop(i)
                    i -= 1
                    continue
                else: 
                    if i == 0:
                        i += 1
                        continue
                    else:
                        asteroids.pop(i)
                        i -= 1
                        continue
            else:
                i += 1
                    
                
             