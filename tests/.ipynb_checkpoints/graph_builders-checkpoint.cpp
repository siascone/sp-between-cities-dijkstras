#include "../code/Edge.h"
#include "../code/Graph.h"
#include "../code/Node.h"

Graph* mkSmallLocalGraph() {
    Graph* smGraph(new Graph());

    // initialize city nodes
    Node* boulder(new Node("Boulder"));
    Node* longmont(new Node("Longmont"));
    Node* gunbarrel(new Node("Gunbarrel"));
    Node* niwot(new Node("Niwot"));
    Node* hygiene(new Node("Hygiene"));

    // initialize edges
    Edge* boulder_hygiene(new Edge(boulder, hygiene, 15.3));
    Edge* hygiene_boulder(new Edge(hygiene, boulder, 15.3));

    Edge* boulder_niwot(new Edge(boulder, niwot, 8.7));
    Edge* niwot_boulder(new Edge(niwot, boulder, 8.7));

    Edge* boulder_gunbarrel(new Edge(boulder, gunbarrel, 7.8));
    Edge* gunbarrel_boulder(new Edge(gunbarrel, boulder, 7.8));

    Edge* hygiene_niwot(new Edge(hygiene, niwot, 8));
    Edge* niwot_hygiene(new Edge(niwot, hygiene, 8));

    Edge* hygiene_longmont(new Edge(hygiene, longmont, 5.5));
    Edge* longmont_hygiene(new Edge(longmont, hygiene, 5.5));

    Edge* niwot_longmont(new Edge(niwot, longmont, 7.1));
    Edge* longmont_niwot(new Edge(longmont, niwot, 7.1));

    Edge* niwot_gunbarrel(new Edge(niwot, gunbarrel, 4.5));
    Edge* gunbarrel_niwot(new Edge(gunbarrel, niwot, 4.5));

    Edge* gunbarrel_longmont(new Edge(gunbarrel, longmont, 12.2));
    Edge* longmont_gunbarrel(new Edge(longmont, gunbarrel, 12.2));

    // add city nodes to graph
    smGraph->addNode(boulder);
    smGraph->addNode(longmont);
    smGraph->addNode(gunbarrel);
    smGraph->addNode(niwot);
    smGraph->addNode(hygiene);

    // add edges to graph
    // outgoing from boulder and back
    smGraph->addEdge(boulder_hygiene);
    smGraph->addEdge(hygiene_boulder);

    smGraph->addEdge(boulder_niwot);
    smGraph->addEdge(niwot_boulder);

    smGraph->addEdge(boulder_gunbarrel);
    smGraph->addEdge(gunbarrel_boulder);

    // outgoing from hygiene and back
    smGraph->addEdge(hygiene_niwot);
    smGraph->addEdge(niwot_hygiene);

    smGraph->addEdge(hygiene_longmont);
    smGraph->addEdge(longmont_hygiene);

    // outgoing from niwot and back
    smGraph->addEdge(niwot_longmont);
    smGraph->addEdge(longmont_niwot);

    smGraph->addEdge(niwot_gunbarrel);
    smGraph->addEdge(gunbarrel_niwot);
    
    // outgoing from gunbarrel and back
    smGraph->addEdge(gunbarrel_longmont);
    smGraph->addEdge(longmont_gunbarrel);

    return smGraph;
}

Graph* mkLargeLocalGraph() {
    Graph* lgGraph(new Graph());
    
    // initialize city nodes
    Node* boulder(new Node("Boulder"));
    Node* gunbarrel(new Node("Gunbarrel"));
    Node* niwot(new Node("Niwot"));
    Node* lyons(new Node("Lyons"));
    Node* hygiene(new Node("Hygiene"));
    Node* longmont(new Node("Longmont"));
    Node* erie(new Node("Erie"));
    Node* lafayette(new Node("Lafayette"));
    Node* louisville(new Node("Louisville"));
    Node* superior(new Node("Superior"));
    Node* eldorado_springs(new Node("Eldorado Springs"));
    Node* broomfield(new Node("Broomfield"));
    
    // inialize edges
    // outgoing from boulder and back
    Edge* boulder_gunbarrel(new Edge(boulder, gunbarrel, 7.8));
    Edge* gunbarrel_boulder(new Edge(gunbarrel, boulder, 7.8));
    
    Edge* boulder_niwot(new Edge(boulder, niwot, 8.7));
    Edge* niwot_boulder(new Edge(niwot, boulder, 8.7));
    
    Edge* boulder_hygiene(new Edge(boulder, hygiene, 15.3));
    Edge* hygiene_bloulder(new Edge(hygiene, boulder, 15.3));
    
    Edge* boulder_lyons(new Edge(boulder, lyons, 15.9));
    Edge* lyons_boulder(new Edge(lyons, boulder, 15.9));
    
    Edge* boulder_erie(new Edge(boulder, erie, 14.2));
    Edge* erie_boulder(new Edge(erie, boulder, 14.2));
    
    Edge* boulder_lafayette(new Edge(boulder, lafayette, 11.9));
    Edge* lafayette_boulder(new Edge(lafayette, boulder, 11.9));
    
    Edge* boulder_louisville(new Edge(boulder, louisville, 9.9));
    Edge* louisville_boulder(new Edge(louisville, boulder, 9.9));
    
    Edge* boulder_superior(new Edge(boulder, superior, 8.4));
    Edge* superior_boulder(new Edge(superior, boulder, 8.4));
    
    Edge* boulder_eldorado_springs(new Edge(boulder, eldorado_springs, 8.6));
    Edge* eldorado_springs_boulder(new Edge(eldorado_springs, boulder, 8.6));
    
    // outgoing from gunbarrel and back
    Edge* gunbarrel_niwot(new Edge(gunbarrel, niwot, 4.5));
    Edge* niwot_gunbarrel(new Edge(niwot, gunbarrel, 4.5));
    
    Edge* gunbarrel_longmont(new Edge(gunbarrel, longmont, 12.2));
    Edge* longmont_gunbarrel(new Edge(longmont, gunbarrel, 12.2));
    
    Edge* gunbarrel_erie(new Edge(gunbarrel, erie, 9.9));
    Edge* erie_gunbarrel(new Edge(erie, gunbarrel, 9.9));
    
    Edge* gunbarrel_lafayette(new Edge(gunbarrel, lafayette, 10));
    Edge* lafayette_gunbarrel(new Edge(lafayette, gunbarrel, 10));
    
    // outgoing from lyons and back
    Edge* lyons_hygiene(new Edge(lyons, hygiene, 6.4));
    Edge* hygiene_lyons(new Edge(hygiene, lyons, 6.4));
    
    Edge* lyons_longmont(new Edge(lyons, longmont, 11.9));
    Edge* longmont_lyons(new Edge(longmont, lyons, 11.9));
    
    // outgoing from niwot and back
    Edge* niwot_hygiene(new Edge(niwot, hygiene, 8));
    Edge* hygiene_niwot(new Edge(hygiene, niwot, 8));
    
    Edge* niwot_longmont(new Edge(niwot, longmont, 7.1));
    Edge* longmont_niwot(new Edge(longmont, niwot, 7.1));
    
    // outgoing from hygiene and back
    Edge* hygiene_longmont(new Edge(hygiene, longmont, 5.5));
    Edge* longmont_hygiene(new Edge(longmont, hygiene, 5.5));
    
    // outgoing from longmont and back
    Edge* longmont_erie(new Edge(longmont, erie, 10.7));
    Edge* erie_longmont(new Edge(erie, longmont, 10.7));
    
    // outgoing from erie and back
    Edge* erie_lafayette(new Edge(erie, lafayette, 6.2));
    Edge* lafayette_erie(new Edge(lafayette, erie, 6.2));
    
    Edge* erie_broomfield(new Edge(erie, broomfield, 11.5));
    Edge* broomfield_erie(new Edge(broomfield, erie, 11.5));
    
    // outgoing from lafayette and aback
    Edge* lafayette_louisville(new Edge(lafayette, louisville, 3.3));
    Edge* louisville_lafayette(new Edge(louisville, lafayette, 3.3));
    
    Edge* lafayette_broomfield(new Edge(lafayette, broomfield, 5.6));
    Edge* broomfield_lafayette(new Edge(broomfield, lafayette, 5.6));
    
    // outgoing from louisville and back
    Edge* louisville_superior(new Edge(louisville, superior, 3.6));
    Edge* superior_louisville(new Edge(superior, louisville, 3.6));
    
    Edge* louisville_broomfield(new Edge(louisville, broomfield, 6.5));
    Edge* broomfield_louisville(new Edge(broomfield, louisville, 6.5));
    
    // outgoing from superior and back
    Edge* superior_eldorado_springs(new Edge(superior, eldorado_springs, 7.2));
    Edge* eldorado_springs_superior(new Edge(eldorado_springs, superior, 7.2));
    
    Edge* superior_broomfield(new Edge(superior, broomfield, 6.3));
    Edge* broomfield_superior(new Edge(broomfield, superior, 6.3));
    
    // outgoing from eldorado springs
    Edge* eldorado_springs_broomfield(new Edge(eldorado_springs, broomfield, 12.8));
    Edge* broomfield_eldorado_springs(new Edge(broomfield, eldorado_springs, 12.8));
    
    // add city nodes to graph
    lgGraph->addNode(boulder);
    lgGraph->addNode(gunbarrel);
    lgGraph->addNode(niwot);
    lgGraph->addNode(lyons);
    lgGraph->addNode(hygiene);
    lgGraph->addNode(longmont);
    lgGraph->addNode(erie);
    lgGraph->addNode(lafayette);
    lgGraph->addNode(louisville);
    lgGraph->addNode(superior);
    lgGraph->addNode(eldorado_springs);
    lgGraph->addNode(broomfield);
    
    // add edges to graph
    lgGraph->addEdge(boulder_gunbarrel);
    lgGraph->addEdge(gunbarrel_boulder);
    
    lgGraph->addEdge(boulder_niwot);
    lgGraph->addEdge(niwot_boulder);
    
    lgGraph->addEdge(boulder_hygiene);
    lgGraph->addEdge(hygiene_bloulder);
    
    lgGraph->addEdge(boulder_lyons);
    lgGraph->addEdge(lyons_boulder);
    
    lgGraph->addEdge(boulder_erie);
    lgGraph->addEdge(erie_boulder);
    
    lgGraph->addEdge(boulder_lafayette);
    lgGraph->addEdge(lafayette_boulder);
    
    lgGraph->addEdge(boulder_louisville);
    lgGraph->addEdge(louisville_boulder);
    
    lgGraph->addEdge(boulder_superior);
    lgGraph->addEdge(superior_boulder);
    
    lgGraph->addEdge(boulder_eldorado_springs);
    lgGraph->addEdge(eldorado_springs_boulder);
    
    lgGraph->addEdge(gunbarrel_niwot);
    lgGraph->addEdge(niwot_gunbarrel);
    
    lgGraph->addEdge(gunbarrel_longmont);
    lgGraph->addEdge(longmont_gunbarrel);
    
    lgGraph->addEdge(gunbarrel_erie);
    lgGraph->addEdge(erie_gunbarrel);
    
    lgGraph->addEdge(gunbarrel_lafayette);
    lgGraph->addEdge(lafayette_gunbarrel);
    
    lgGraph->addEdge(lyons_hygiene);
    lgGraph->addEdge(hygiene_lyons);
    
    lgGraph->addEdge(lyons_longmont);
    lgGraph->addEdge(longmont_lyons);
    
    lgGraph->addEdge(niwot_hygiene);
    lgGraph->addEdge(hygiene_niwot);
    
    lgGraph->addEdge(niwot_longmont);
    lgGraph->addEdge(longmont_niwot);
    
    lgGraph->addEdge(hygiene_longmont);
    lgGraph->addEdge(longmont_hygiene);
    
    lgGraph->addEdge(longmont_erie);
    lgGraph->addEdge(erie_longmont);
    
    lgGraph->addEdge(erie_lafayette);
    lgGraph->addEdge(lafayette_erie);
    
    lgGraph->addEdge(erie_broomfield);
    lgGraph->addEdge(broomfield_erie);
    
    lgGraph->addEdge(lafayette_louisville);
    lgGraph->addEdge(louisville_lafayette);
    
    lgGraph->addEdge(lafayette_broomfield);
    lgGraph->addEdge(broomfield_lafayette);
    
    lgGraph->addEdge(louisville_superior);
    lgGraph->addEdge(superior_louisville);
    
    lgGraph->addEdge(louisville_broomfield);
    lgGraph->addEdge(broomfield_louisville);
    
    lgGraph->addEdge(superior_eldorado_springs);
    lgGraph->addEdge(eldorado_springs_superior);
    
    lgGraph->addEdge(superior_broomfield);
    lgGraph->addEdge(broomfield_superior);
    
    lgGraph->addEdge(eldorado_springs_broomfield);
    lgGraph->addEdge(broomfield_eldorado_springs);
    
    return lgGraph;
                     
}