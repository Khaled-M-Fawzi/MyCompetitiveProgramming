# Probability Theory

**Probability** refers to the extent of occurrence of events. When an event occurs like throwing a ball, picking a card from deck, etc ., then the must be some probability associated with that event.

In terms of mathematics, probability refers to the ratio of wanted outcomes to the total number of possible outcomes (wanted outcomes/total outcomes). 

**Probability of an Event** – If there are total p possible outcomes associated with a random experiment and q of them are favourable outcomes to the event A, then the probability of event A is denoted by P(A) and is given by P(A) = q/p 

The probability of non occurrence of event A, i.e, P(A’) = 1 – P(A)

**Note**

- If the value of P(A) = 1, then event A is called sure event .
- If the value of P(A) = 0, then event A is called impossible event.
- Also, P(A) + P(A’) = 1

**Theorems**

**General** : Let A, B, C are the events associated with a random experiment, then

- P(A∪B) = P(A) + P(B) – P(A∩B)
- P(A∪B) = P(A) + P(B) if A and B are mutually exclusive
- P(A∪B∪C) = P(A) + P(B) + P(C) – P(A∩B) – P(B∩C)- P(C∩A) + P(A∩B∩C)
- P(A∩B’) = P(A) – P(A∩B)
- P(A’∩B) = P(B) – P(A∩B)

**Extension of Multiplication Theorem** : Let A1, A2, ….., An are n events associated with a random experiment, then

P(A1∩A2∩A3 ….. An) = P(A1)P(A2/A1)P(A3/A2∩A1) ….. P(An/A1∩A2∩A3∩ ….. ∩An-1)

**Example1** : A bag contains 10 oranges and 20 apples out of which 5 apples and 3 oranges are defective .If a person takes out two at random, what is the probability that either both are good or both are apples ?

**Solution** : Out of 30 items, two can selected in 30C2 ways . Thus, Total elementary events = 30C2 .

Consider the events :

A = Getting two apples

B = Getting two good items

Required Probability is : P(A∪B) = P(A) + P(B) – P(A∩B) 

There are 20 apples, out of which 2 can drawn in 20C2 ways . P(A) = 20C2/30C2

There are 8 defective items and 22 are good, Out of 22 good items, two can be can drawn in 22C2 ways . P(B) = 22C2/30C2

Sice there are 15 items which are good apples, out of which 2 can be selected in 15C2 ways . P(A∩B) = 15C2/30C2

Substituting the values of P(A), P(B) and P(A∩B) 

Required probability is = (20C2/30C2) + (22C2/30C2) – (15C2/30C2) = 316/435

**Example** : The probability that a person will get an electric contract is 2/5 and probability that he will not get plumbing contract is 4/7 . If the probability of getting at least one contact is 2/3, what is the probability of getting both ?

**Solution** : Consider the two events:

A = Person gets electric contract

B = Person gets plumbing contract

We have,

P(A) = 2/5

P(B’) = 4/7

P(A∪B) = 2/3

Now, P(A∩B) = P(A) + P(B) – P(A∪B) = (2/5) + (1 – 4/7) – (2/3) = 17/105

**Total Law of Probability** : Let S be the sample space associated with a random experiment and E1, E2, …, En be n mutually exclusive and exhaustive events associated with the random experiment . If A is any event which occurs with E1 or E2 or … or En, then

```P(A) = P(E1)P(A/E1) + P(E2)P(A/E2) + ... +  P(En)P(A/En)```

**Example1** : A bag contains 3 black balls and 4 red balls .A second bag contains 4 black balls and 2 red balls. One bag is selected at random. From the selected bag, one ball is drawn. Find the probability that the ball drawn is red.

**Solution** :
A red ball can be drawn in two ways:

Selecting bag I and then drawing a red ball from it .

Selecting bag II and then drawing a red ball from it .

Let E1, E2 and A be the defined events as follows :

E1 = Selecting bag I

E2 = Selecting bag II

A = Drawing red ball

Since selecting one of the two bags at random .

P(E1) = 1/2

P(E2) = 1/2

Now, probability of drawing red ball when first bag has been chosen

P(A/E1) = 4/7

and, probability of drawing red ball when second bag has been chosen

P(A/E2) = 2/6

Using total law of probability, we have

P(A) = P(E1)P(A/E1) + P(E2)P(A/E2) = (1/2)(4/7) + (1/2)(2/6) = 19/42

Hence, the probability of drawing a red ball is 19/42

**Example** : In a bulb factory, three machines namely A, B, C produces 25%, 35% and 40% of the total bulbs respectively . Of their output, 5, 4 and 2 percent are defective bulbs respectively . A bulb is drawn is drawn at random from products . What is the probability that bulb drawn is defective ?

**Solution** : Let E1, E2, E3 and A be the defined events as follows :

E1 = The bulb is manufactured by machine A, P(E1) = 25/100

E2 = The bulb is manufactured by machine B, P(E2) = 35/100

E3 = The bulb is manufactured by machine C, P(E3) = 40/100

A = The bulb is defective 

Now, probability that the bulb is defective given that is produced by Machine A, P(A/E1) = 5/100

and, probability that the bulb is defective given that is produced by Machine B, P(A/E2) = 4/100

and, probability that the bulb is defective given that is produced by Machine C, P(A/E3) = 2/100

Using total law of probability, we have

P(A) = P(E1)P(A/E1) + P(E2)P(A/E2) + P(E3)P(A/E3) = (25/100)(5/100) + (35/100)(4/100) + (40/100)(2/100) = 0.0345

Hence, the probability that the bulb is defective is 0.0345

### Conditional Probability

Conditional probability P(A | B) indicates the probability of event ‘A’ happening given that event B happened.
    
احتمال وقوع أ بشرط وقوع ب

```P(A|B) = P(A∩B) / P(B)```

We can easily understand the above formula using [the diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Math/conditional_probab.png). Since B has already happened, the sample space reduces to B. So the probability of A happening becomes P(A∩B) divided by P(B)

**Example** : In a batch, there are 80% C programmers, and 40% are Java and C programmers. What is the probability that a C programmer is also Java programmer?

Let A --> Event that a student is Java programmer

Let B --> Event that a student is C programmer
    
P(A|B) = P(A ∩ B) / P(B) = (0.4) / (0.8) = 0.5

So there are 50% chances that student that knows C also knows Java.

**Product Rule** : Derived from above definition of conditional probability by multiplying both sides with P(B)

P(A ∩ B) = P(B) * P(A|B) 

From the product rule :

- X ⊆ Y  implies P(X|Y) = P(X)/P(Y)
- Y ⊆ X  implies P(X|Y) = 1

**Understanding Conditional probability through tree** :
Computation for Conditional Probability can be done using tree, This method is very handy as well as fast when for many problems.

**Example** : In a certain library, twenty percent of the fiction books are worn and need replacement. Ten percent of the non-fiction books are worn and need replacement. Forty percent of the library’s books are fiction and sixty percent are non-fiction. What is the probability that a book chosen at random are worn? Draw a tree diagram representing the data.

Solution: Let F represents fiction books and N represents non-fiction books. Let W represents worn books and G represents non-worn books. see [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Math/condi.png)

P(worn)= P(N) * P(W | N) + P(F) * P(W | F) = 0.6 * 0.1  +  0.4 * 0.2  = 0.14

**Bayes’s formula**

```P(A|B) = P(B|A) * P(A) / P(B)```

P(A|B) = P(A∩B) / P(B)   ==>>  P(A∩B) = P(A|B) * P(B)

P(B|A) = P(B∩A) / P(A)   ==>> P(B∩A) =  P(B|A) * P(A)

 P(A∩B) = P(B∩A)
 
 P(A|B) * P(B) = P(B|A) * P(A)
 
 P(X) = P(X∩Y) + P(X∩Y^c)  .