'''
두 문자의 겹침을 확인할 수 있는 알고리즘 

작은 문자에서부터 시작함


'''


        



        # word의 끝 idx에 


class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        table = {}
        for i in wordDict:
            table[i] = True


            
        def boirmoore(st1, st2):
            if not st1:
                return True
            if st1 in table:
                return table[st1]
            

            print(st1, st2)
            dic = {}
            for i, j in enumerate(st2):
                dic[j] = len(st2) - i - 1
            # dic[st2[-1]] = 0
            # dic.pop(st2[-1])
            # 역행하는일은 없어야하니까 마지막거를 빼는 방식으로 했다
            # 근데 여기서 문제가 있는데 난 흔적을 남기지 않고 지우는 방식으로 했다가
            # 있었다는 흔적이 지워져 버리는 현상이 발생해서 문제가 됐다
            # 그럼 흔적을 남겨야되는데. 남기면 종료조건이 애매해진다. 
            # 종료조건은 set으로 해결했는데 시간을 줄일 수 있었던 메모리제이션 자체가 
            # 불가능해져서 그걸 다시 빼내는 작업을 꼭 해야할지

            ''' 
            어려운 문제는 이런 게 많은것같아
            딜레마적인 문제들 지금 전부다 저 * 때문에 생긴 일들인데 저게 해결이
            안됨
             * 을 쓰지말고 리스트로 나누자 
            '''
            # print(dic)
            limit = len(st1) - 1
            word = len(st2) - 1
            while word <= limit:
                # print(word)
                inner_idx = 0

                '''
                
                마지막 숫자부터 차례대로 비교한다 
                
                '''
                # print(word)
                while len(st2) - inner_idx > 0  and st2[len(st2) - 1 - inner_idx] == st1[word - inner_idx]:
                    
                    inner_idx += 1
                
                if len(st2) - inner_idx == 0:
                    for i in wordDict:
                        # print(st1[:word + 1 - inner_idx] + st1[word + 1 :])
                        # if st1[:word + 1 - inner_idx] + st1[word + 1 :] in table:
                        #     return True'
                        # if st1[:word + 1 - inner_idx] + st1[word + 1 :] in table:
                        if boirmoore(st1[:word + 1 - inner_idx], i) and boirmoore(st1[word + 1 :], i):
                            table[st1[:word + 1 - inner_idx] + st1[word + 1 :]] = True
                            return True
                    else:
                        

                        table[st1[word + 1 :]] = False
                        table[st1[:word + 1 - inner_idx]] = False

                        # if i in (st1[:word + 1 - inner_idx] + '*' + st1[word + 1 :]).split('*'):
                        #     if boirmoore(st1[:word + 1 - inner_idx] + '*' + st1[word + 1 :], i):
                        #         table[st1[:word + 1 - inner_idx] + st1[word + 1 :]] = True
                        #         return True
                    word += len(st2)
                    continue
                '''
                같지 않은 경우가 생겼다 
                '''
                # 겹치는 경우가 있을 때만 이 조건에 온다.
                # 겹치는 애 있건 없건 그 문자가 맨오른쪽까지 가는데 얼마나 움직여야하는지를 알아야한다
                # print(word - inner_idx)
                if inner_idx < dic.get(st1[word - inner_idx], 0):
                    word +=  dic.get(st1[word - inner_idx], len(st2))
                else:
                    word += len(st2) - inner_idx
            # print(table)
            # table[st1] = False
            return False
        # 보이어 무어를 통해서 같은 애가 있을 때만 

        default = False

        # while wordDict:
        #     if boirmoore(s, wordDict[-1]):
        #         default = True
        #         break
        #     wordDict.pop()

        for word in wordDict:
            if boirmoore(s, word):
                default = True
                break
        print(table)
        return default
        

a = Solution()














s = "ccbb"
wordDict =\
["bc","cb"]



s = "catsandog"
wordDict = ["cats","dog","sand","and","cat"]
s = 'applepenapple'
wordDict = ["apple","pen"]
s = "ccbb"
wordDict =\
["bc","cb"]
s = 'leetcode'
wordDict = ["leet","code"]
s = "fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami"
wordDict = ["kfomka","hecagbngambii","anobmnikj","c","nnkmfelneemfgcl","ah","bgomgohl","lcbjbg","ebjfoiddndih","hjknoamjbfhckb","eioldlijmmla","nbekmcnakif","fgahmihodolmhbi","gnjfe","hk","b","jbfgm","ecojceoaejkkoed","cemodhmbcmgl","j","gdcnjj","kolaijoicbc","liibjjcini","lmbenj","eklingemgdjncaa","m","hkh","fblb","fk","nnfkfanaga","eldjml","iejn","gbmjfdooeeko","jafogijka","ngnfggojmhclkjd","bfagnfclg","imkeobcdidiifbm","ogeo","gicjog","cjnibenelm","ogoloc","edciifkaff","kbeeg","nebn","jdd","aeojhclmdn","dilbhl","dkk","bgmck","ohgkefkadonafg","labem","fheoglj","gkcanacfjfhogjc","eglkcddd","lelelihakeh","hhjijfiodfi","enehbibnhfjd","gkm","ggj","ag","hhhjogk","lllicdhihn","goakjjnk","lhbn","fhheedadamlnedh","bin","cl","ggjljjjf","fdcdaobhlhgj","nijlf","i","gaemagobjfc","dg","g","jhlelodgeekj","hcimohlni","fdoiohikhacgb","k","doiaigclm","bdfaoncbhfkdbjd","f","jaikbciac","cjgadmfoodmba","molokllh","gfkngeebnggo","lahd","n","ehfngoc","lejfcee","kofhmoh","cgda","de","kljnicikjeh","edomdbibhif","jehdkgmmofihdi","hifcjkloebel","gcghgbemjege","kobhhefbbb","aaikgaolhllhlm","akg","kmmikgkhnn","dnamfhaf","mjhj","ifadcgmgjaa","acnjehgkflgkd","bjj","maihjn","ojakklhl","ign","jhd","kndkhbebgh","amljjfeahcdlfdg","fnboolobch","gcclgcoaojc","kfokbbkllmcd","fec","dljma","noa","cfjie","fohhemkka","bfaldajf","nbk","kmbnjoalnhki","ccieabbnlhbjmj","nmacelialookal","hdlefnbmgklo","bfbblofk","doohocnadd","klmed","e","hkkcmbljlojkghm","jjiadlgf","ogadjhambjikce","bglghjndlk","gackokkbhj","oofohdogb","leiolllnjj","edekdnibja","gjhglilocif","ccfnfjalchc","gl","ihee","cfgccdmecem","mdmcdgjelhgk","laboglchdhbk","ajmiim","cebhalkngloae","hgohednmkahdi","ddiecjnkmgbbei","ajaengmcdlbk","kgg","ndchkjdn","heklaamafiomea","ehg","imelcifnhkae","hcgadilb","elndjcodnhcc","nkjd","gjnfkogkjeobo","eolega","lm","jddfkfbbbhia","cddmfeckheeo","bfnmaalmjdb","fbcg","ko","mojfj","kk","bbljjnnikdhg","l","calbc","mkekn","ejlhdk","hkebdiebecf","emhelbbda","mlba","ckjmih","odfacclfl","lgfjjbgookmnoe","begnkogf","gakojeblk","bfflcmdko","cfdclljcg","ho","fo","acmi","oemknmffgcio","mlkhk","kfhkndmdojhidg","ckfcibmnikn","dgoecamdliaeeoa","ocealkbbec","kbmmihb","ncikad","hi","nccjbnldneijc","hgiccigeehmdl","dlfmjhmioa","kmff","gfhkd","okiamg","ekdbamm","fc","neg","cfmo","ccgahikbbl","khhoc","elbg","cbghbacjbfm","jkagbmfgemjfg","ijceidhhajmja","imibemhdg","ja","idkfd","ndogdkjjkf","fhic","ooajkki","fdnjhh","ba","jdlnidngkfffbmi","jddjfnnjoidcnm","kghljjikbacd","idllbbn","d","mgkajbnjedeiee","fbllleanknmoomb","lom","kofjmmjm","mcdlbglonin","gcnboanh","fggii","fdkbmic","bbiln","cdjcjhonjgiagkb","kooenbeoongcle","cecnlfbaanckdkj","fejlmog","fanekdneoaammb","maojbcegdamn","bcmanmjdeabdo","amloj","adgoej","jh","fhf","cogdljlgek","o","joeiajlioggj","oncal","lbgg","elainnbffk","hbdi","femcanllndoh","ke","hmib","nagfahhljh","ibifdlfeechcbal","knec","oegfcghlgalcnno","abiefmjldmln","mlfglgni","jkofhjeb","ifjbneblfldjel","nahhcimkjhjgb","cdgkbn","nnklfbeecgedie","gmllmjbodhgllc","hogollongjo","fmoinacebll","fkngbganmh","jgdblmhlmfij","fkkdjknahamcfb","aieakdokibj","hddlcdiailhd","iajhmg","jenocgo","embdib","dghbmljjogka","bahcggjgmlf","fb","jldkcfom","mfi","kdkke","odhbl","jin","kcjmkggcmnami","kofig","bid","ohnohi","fcbojdgoaoa","dj","ifkbmbod","dhdedohlghk","nmkeakohicfdjf","ahbifnnoaldgbj","egldeibiinoac","iehfhjjjmil","bmeimi","ombngooicknel","lfdkngobmik","ifjcjkfnmgjcnmi","fmf","aoeaa","an","ffgddcjblehhggo","hijfdcchdilcl","hacbaamkhblnkk","najefebghcbkjfl","hcnnlogjfmmjcma","njgcogemlnohl","ihejh","ej","ofn","ggcklj","omah","hg","obk","giig","cklna","lihaiollfnem","ionlnlhjckf","cfdlijnmgjoebl","dloehimen","acggkacahfhkdne","iecd","gn","odgbnalk","ahfhcd","dghlag","bchfe","dldblmnbifnmlo","cffhbijal","dbddifnojfibha","mhh","cjjol","fed","bhcnf","ciiibbedklnnk","ikniooicmm","ejf","ammeennkcdgbjco","jmhmd","cek","bjbhcmda","kfjmhbf","chjmmnea","ifccifn","naedmco","iohchafbega","kjejfhbco","anlhhhhg"]# # print('bdbdfdf**Bbdb8B*B8BBB8***Bb'.split('*'))
# s = "bccdbacdbdacddabbaaaadababadad"
# wordDict =\
# ["cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa","bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb","dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb"]
# s = "aaaaaaa"
# wordDict =\
# ["aaaa","aaa"]


print(a.wordBreak(s, wordDict))

# 또 하나의 문제가 