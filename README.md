# L Systems
An implementation of Bresenham's line and circle drawing algorithms and deterministic context-free L systems

Following are few of the results produced:

1. A Gulmohar-like tree:

    Axiom: S
    
    Production rules:
    
                        S -> FB
                        B -> F[+BLMR]F[-BMR]F[+BL][-BLMR]
                        F -> FN
                        N -> F
                        L -> [G-G][-G+G]--[G-G][-G+G]++++[G-G][-G+G]--
                        R -> Y[MP][/MP][\MP]
                        
    Phenotypes:
    
                        F -> (DRAW_FORWARD, 10.0, brown)
                        G -> (DRAW_FORWARD, 5.0, green)
                        M -> (MOVE_FORWARD, 2.0)
                        Y -> (DRAW_CIRCLE, 1.0, yellow)
                        P -> (DRAW_CIRCLE, 2.0, red)
                        [ -> (SAVE)
                        ] -> (RETURN)
                        + -> (ROTATE, +22.5)
                        - -> (ROTATE, -22.5)
                        / -> (ROTATE, -36)
                        \ -> (ROTATE, 36)
                        
    Results:
    
    ![n=3](/img/1_1.png?raw=true "n=3")
    ![n=5](/img/1_2.png?raw=true "n=5")
    ![n=7](/img/1_3.png?raw=true "n=7")
    
    
2. A blueberry plant:

    Axiom: S

    Production rules:

                        S -> B
                        B -> FL[++LBLMR]FL[+BLMR]--FLR[BLMR]++
                        L -> //[G/G][/G\G]\[G/G][/G\G]\\[G/G][/G\G]\[G/G][/G\G]//
                        R -> Y[MP][//MP][////MMP][\\MP][\\\\MMP]
                        
    Phenotypes:

                        F -> (DRAW_FORWARD, 20.0, brown)
                        G -> (DRAW_FORWARD, 7.0, green)
                        M -> (MOVE_FORWARD, 2.0)
                        P -> (DRAW_CIRCLE, 2.0, indigo)
                        [ -> (SAVE)
                        ] -> (RETURN)
                        + -> (ROTATE, +15)
                        - -> (ROTATE, -15)
                        \ -> (ROTATE, +22.5)
                        / -> (ROTATE, -22.5)
                        
    Results:
    
    ![n=2](/img/2_1.png?raw=true "n=2")
    ![n=4](/img/2_2.png?raw=true "n=4")
    ![n=6](/img/2_3.png?raw=true "n=6")
    

3. Dried Grass:

    Axiom: W

    Production rules:

                        V -> [+++W][---W]YV
                        W -> +X[-W]Z
                        X -> -W[+X]Z
                        Y -> YZ
                        Z -> [-FFF][+FFF]F
                        
    Phenotypes:

                        F -> (DRAW_FORWARD, 7.5, brown)
                        [ -> (SAVE)
                        ] -> (RETURN)
                        
    Results:
    
    ![n=2](/img/3_1.png?raw=true "n=2")
    ![n=4](/img/3_2.png?raw=true "n=4")
    ![n=6](/img/3_3.png?raw=true "n=6")
    ![n=8](/img/3_4.png?raw=true "n=8")
