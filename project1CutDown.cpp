//Project1 creating the twitter tweeter
//first step is to parse data and place it in an array (of size 280 chars)
//second step is to use the markovian chain algorithm on the array
//markov property only depends on where i am now and not the past.
//treat every word as a state and predict the next word based on the previous state
//when a word is added, have to add one to total for that pair and add 
//one to the word appearing next based on the prev state and then divide by the 
//total to get the percentage that that word will be next
//third step is to spit out your own tweet no greater than 280 characters


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <time.h>
using namespace std;


int main(){
	//typedef vector<string> vecString;
  	srand(time(NULL));
	//multimap<pair<string,string>, pair<string,double>> markovMMap;
	multimap<pair<string,string>, string> markovMMap;
	
	int i=0;
	vector<string> tweetVect;
  	string strTweet;
	ifstream file;
	ofstream outFile;
	
	file.open("tweet2.txt");
	if(!file){
		outFile.open("tweetOut2.txt");
		outFile << "input file does not exist";
	}
	else{
		while(file >> strTweet){
			tweetVect.push_back(strTweet);
			if(i>1){
				markovMMap.insert(make_pair(make_pair(tweetVect[i-2],tweetVect[i-1]),tweetVect[i]));

			}
			else if(i==1){
				markovMMap.insert(make_pair(make_pair("empty",tweetVect[i-1]),tweetVect[i]));
		
			}
			else{
				markovMMap.insert(make_pair(make_pair("empty","empty"),tweetVect[i]));
	
			}
			i++;
		}

		//multimap<pair<string,string>,string>::iterator iter1;
		//multimap<pair<string,string>,string>::iterator iter2;
	
		outFile.open("tweetOut2.txt");	
	
		multimap<pair<string,string>,string>::iterator iter;

  
  
  		//dene's attempt
  		int charCount = 0;
  		vector<string> wordTracker; //to keep track of the words placed into our tweet
  		int wordTrackerIndex = 0;
		int randIndex;
  		pair<multimap<pair<string,string>,string>::iterator, multimap<pair<string,string>,string>::iterator> result = markovMMap.equal_range(pair<string,string> ("empty","empty"));

  		vector<string> randProbWord;
  		i = 0;
  		for(iter = result.first; iter != result.second; ++iter){
    			randProbWord.push_back(iter->second);
    			//cout << randProbWord[i] << endl;
    			i++;
  		}	
  		if(randProbWord.size() == 0){
			charCount = 281;
		}
		else{
			//cout << randProbWord.size() << endl;  
  			randIndex = rand()%randProbWord.size();
  			//cout << randIndex << endl;
  			outFile << randProbWord[randIndex] << " ";
  			charCount += randProbWord[randIndex].length() + 1; //the plus one is to account for the spaces
  			cout << charCount << endl;
  			wordTracker.push_back(randProbWord[randIndex]);
		}
  		while(!randProbWord.empty()){
    			randProbWord.pop_back();
  		}

  
  		result = markovMMap.equal_range(pair<string,string> ("empty",wordTracker[0]));

  		i = 0;
  		for(iter = result.first; iter != result.second; ++iter){
    			randProbWord.push_back(iter->second);
    			i++;
  		}
		if(randProbWord.size() == 0 || charCount == 281){
			charCount = 281;
		}
		else{
	  		randIndex = rand()%randProbWord.size();
  			outFile << randProbWord[randIndex] << " ";
  			charCount += randProbWord[randIndex].length() + 1; 
  			cout << charCount << endl;
  			wordTracker.push_back(randProbWord[randIndex]);
  			wordTrackerIndex += 1;
		}
  		while(!randProbWord.empty()){
    			randProbWord.pop_back();
  		}
  
  		while(charCount < 280){
    			result = markovMMap.equal_range(pair<string,string> (wordTracker[wordTrackerIndex-1],wordTracker[wordTrackerIndex])); //previous two words

    			i = 0;
    			for(iter = result.first; iter != result.second; ++iter){
      				randProbWord.push_back(iter->second);
      				i++;
    			}
    			if(randProbWord.size() == 0){
      				charCount = 281; //end the output tweet because the probability that there are no more words has been chosen
    			}	
    			else{ 
      				randIndex = rand()%randProbWord.size();
      				outFile << randProbWord[randIndex] << " ";
      				charCount += randProbWord[randIndex].length() + 1; 
      				cout << charCount << endl;
      				wordTracker.push_back(randProbWord[randIndex]);
      				wordTrackerIndex += 1;

      				while(!randProbWord.empty()){
        				randProbWord.pop_back();
      				}
    			}
  		}

  		while(!randProbWord.empty()){
			randProbWord.pop_back();
		}
		while(!tweetVect.empty()){
			tweetVect.pop_back();
		}
	}
	return 0;

}
