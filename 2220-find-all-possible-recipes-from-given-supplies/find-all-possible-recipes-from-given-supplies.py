from collections import defaultdict

class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        supplies = set(supplies)
        graph = defaultdict(list)
        sup_cnt = dict()

        for i, ingredient in enumerate(ingredients):
            no_sup = []
            target = recipes[i]

            for ing in ingredient:
                if ing not in supplies:
                    no_sup.append(ing)
            
            sup_cnt[target] = len(no_sup)
            
            for sup in no_sup:
                graph[sup].append(target)
        
        st = []

        for key, val in sup_cnt.items():
            if not val:
                st.append(key)
        
        while st:
            cur = st.pop()
            for makable in graph[cur]:
                sup_cnt[makable] -= 1

                if sup_cnt[makable] == 0:
                    st.append(makable)
        
        return [key for key, val in sup_cnt.items() if val == 0]



        