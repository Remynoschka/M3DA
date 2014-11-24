getd();

// MAILLAGE //
[ noeuds , elements ] = MSHLoader('rectangle1.msh');
numElements = size(elements,2);
numNoeuds = size(noeuds,2);     



[segments] = findSegments(elements)
numSegments = size(segments,2);


// parametres physiques
k=10000;
m=1;
g=9.81;

// parametres temps
dt = 0.005;
T =  0.1;

// etat courant
// historique
F_t = zeros(2*numNoeuds,1);
A = zeros(2*numNoeuds,1);
V_t = zeros(2*numNoeuds,1);
X_t = zeros(2*numNoeuds,1);

for i=1:numNoeuds
     X_t([2*i-1 2*i]) = [noeuds(1,i) ; noeuds(2,i)];
end

//init l0
l0 = zeros(numSegments,1);

for i=1:numSegments
    l0(i) = norm(noeuds(:,segments(1,i)) -  noeuds(:,segments(2,i)));
end



for time=0:dt:T,
    // mise à zero des forces
    F_t = zeros(2*numNoeuds,1);
    
    for i=1:numSegments
        p1p2 = noeuds(:,segments(1,i)) - noeuds(:,segments(2,i));
        direction = (p1p2)/norm(p1p2);
        f1 = k * (norm(p1p2) - l0(i)) * direction;
        f2 = -f1;
        F_t(segments(1,i)) = F_t(segments(1,i)) + f1;
        F_t(segments(2,i)) = F_t(segments(2,i)) + f2;
    end
    

    // application du principe fondamental de la dynamique 
    for i=1:numNoeuds
        F_t([2*i]) = F_t([2*i]) - m*g;
        
        
        // fixation du noeud
        P = noeuds(:,i);
        if (P(1)==5),
            F_t([2*i-1]) = 0;
            F_t([2*i]) =0;
        end
        
        A([2*i-1]) = F_t([2*i-1]) / m;
        A([2*i]) = F_t([2*i]) / m;
        
        
    end
    
    
    // Euler explicite
    V_t = V_t + A*dt;    
    X_t = X_t + V_t*dt;
    
    
    
        
    // déplacement du maillage
    noeuds_deplaces = noeuds;
    for i=1:numNoeuds,
      // deplacement selon x
      noeuds_deplaces(1,i) = X_t(2*i-1);
      // deplacement selon y
      noeuds_deplaces(2,i) = X_t(2*i);  
    end
    
  
    
    clf;
    
    draw_mesh( noeuds_deplaces, elements)
    xpause(100);


end

  
  
  
  

  




