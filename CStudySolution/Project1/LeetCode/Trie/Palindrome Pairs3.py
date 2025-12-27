class Solution:
    def palindromePairs(self, words: list[str]) -> list[list[int]]:
        word_dict:dict[str, list[int]] = {}
        result_set:set[tuple[int, int]] = set()
        #O(n)
        for idx, word in enumerate(words):
            word_dict.setdefault(word, []).append(idx)

        #slice word
        #how to find key : larget string need to find smaller string to check pal
        #excep 5 : pal words have same length
        for idx, word in enumerate(word_dict.keys()):
            for slice_idx in range(len(word) + 1):
                left = word[:slice_idx]
                reversed_left = left[::-1]
                right = word[slice_idx:]
                reversed_right = right[::-1]

                #check [left + pal] + inversed left
                if right == right[::-1]:
                    if reversed_left in word_dict:
                        for right_str_idx in word_dict[reversed_left]:
                            if right_str_idx == idx:continue #prevent self pairing
                            result_set.add((idx, right_str_idx))

                #check inversed right + [pal + right]
                if left == left[::-1]:
                    if reversed_right in word_dict:
                        for left_str_idx in word_dict[reversed_right]:
                            if left_str_idx == idx:continue #prevent self pairing
                            result_set.add((left_str_idx, idx))

        return [[i,j] for i, j in result_set]



        #""
        #abcde
        #abc
        #aaaaaa
        #aaa
        #aaab
        #aaa


        #abcde
        #edc

        #pal form

        #""
        #chunk 1 + inverse chunk 1
        #chunk 1 + pal + inverse chunk 1

        #chuck 1 + pal_chunk2_1 + pal_chunk2_2 + inverse_chunk
        #aaabcc + baaa