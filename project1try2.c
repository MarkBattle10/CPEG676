//Project1 creating the twitter tweeter
//first step is to parse data and place it in an array (of size 280 chars)
//second step is to use the markovian chain algorithm on the array
//markov property only depends on where i am now and not the past.
//treat every word as a state and predict the next word based on the previous state
//when a word is added, have to add one to total for that pair and add 
//one to the word appearing next based on the prev state and then divide by the 
//total to get the percentage that that word will be next
//third step is to spit out your own tweet no greater than 280 characters
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct State{
	char *prevWord;
	char *currWord;
	char *nextWord;	
};
struct Word{
	int totalWords;
	int thisWord;
	int probability;
	//struct State wordState;
	char *theCurrentWord;	
};
void calcProbability(struct Word *word, struct State *state){
	word->probability = word->thisWord/word->totalWords;
}

int main(){
	char tweetArr[280];
	//char wordArr[280];
	FILE *tweet;
	FILE *tweetOutput;
	int index=0;
	int indexOut=0;
	int i = 0;
	struct State *wordState;
	struct Word *word;

	wordState = malloc(sizeof(wordState));
	word = malloc(sizeof(word));

	tweet = fopen("/root/CPEG676/tweet.txt", "r");
	tweetOutput = fopen("/root/CPEG676/tweetOutput.txt", "w+");
	//fgets(tweetArr, 280, (FILE*)tweet);

	while(fscanf(tweet, "%s", tweetArr) != EOF){
//		while(tweetArr[index] != 280){
//			for(int ascii=65;ascii<=90;ascii++){
//				if(atoi(tweetArr[index]) == ascii){
//					tweetArr[index] = ;
//				}
//			}
//			for(ascii = 97; ascii<=122; ascii++){
//				if(atoi(tweetArr[index]) == ascii){
//					
//				}
//			}
//			index++;
//		}
		//printf("%s\n", &tweetArr);
		wordState->currWord = tweetArr;
		printf("%c ", wordState->currWord);
		//if(tweetArr[index]!= ' '){
		//	wordState->currWord = tweetArr[index];
			//wordArr[i] = wordState->currWord;
			//i++;
		//}
		//else{
			//could possibly make a list(maybe binsearchtree to find
			//words quickly) of Words (structs) so I can go through
			//to see if the word is already there.
			//if it is already there, look to see if it already has
			//the same previous word, if it does then change the
			//probability of the next words that could be chosen

			//I can get the next word based off the curr word 
			//obtained above and the prevWord. Using this pair,
			//I want to add the next word to have a chance of being
			//chosen after the previous two words. Here I will add
			//1 to the total words that came after the word pair, 
			//and add 1 to that word so that I can calculate the
			//chance it is chosen again
		//	for(int ind=0;ind<strlen(wordArr);ind++){
				
		//	}
		//	calcProbability(word, wordState);

		//}
		//index ++;
	//}
	//while(indexOut != 280){
	//	if(indexOut == 0){

	//	}
	//	else{
	//		fputc(word->nextWord, tweetOutput);
	//	}	
	}
	fclose(tweet);
	fclose(tweetOutput);
	
	free(wordState);
	free(word);	

	return 0;

}
