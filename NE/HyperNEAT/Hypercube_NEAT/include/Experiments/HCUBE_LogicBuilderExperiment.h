#ifndef HCUBE_LOGICBUILDEREXPERIMENT_H_INCLUDED
#define HCUBE_LOGICBUILDEREXPERIMENT_H_INCLUDED

#include "Experiments/HCUBE_Experiment.h"

namespace HCUBE
{
    enum TerrainType
    {
        TERRAIN_TYPE_EMPTY=0,
        TERRAIN_TYPE_FOREST,
        TERRAIN_TYPE_GOLD,
        TERRAIN_TYPE_PEASANT,
        TERRAIN_TYPE_PEASANT_CARRYING_GOLD,
        TERRAIN_TYPE_PEASANT_CARRYING_WOOD,
        TERRAIN_TYPE_BASE,
        TERRAIN_TYPE_END
    };

    class GameState
    {
    public:
        TerrainType terrain[64][64];
        int goldInInventory;

        GameState()
            :
        goldInInventory(0)
        {
            memset(terrain,0,sizeof(TerrainType)*64*64);
        }
    };

    class LogicBuilderExperiment : public Experiment
    {
    public:
    protected:
        GameState state;

        NEAT::FastNetwork<float> transitionTable;

		boost::shared_ptr<const NEAT::GeneticIndividual> substrateIndividual;

    public:
        LogicBuilderExperiment(string _experimentName,int _threadID);

        virtual ~LogicBuilderExperiment()
        {}

        virtual NEAT::GeneticPopulation* createInitialPopulation(int populationSize);

        virtual void populateSubstrate(
            boost::shared_ptr<NEAT::GeneticIndividual> individual
        );

        virtual void processGroup(boost::shared_ptr<NEAT::GeneticGeneration> generation);

        virtual void processIndividualPostHoc(boost::shared_ptr<NEAT::GeneticIndividual> individual);
/*
#ifndef HCUBE_NOGUI
        virtual void createIndividualImage(wxDC &drawContext,boost::shared_ptr<NEAT::GeneticIndividual> individual);

        virtual bool handleMousePress(wxMouseEvent& event,wxSize &bitmapSize);
#endif
*/
        virtual inline bool performUserEvaluations()
        {
            return false;
        }

        virtual inline bool isDisplayGenerationResult()
        {
            return false;
        }

        virtual Experiment* clone();

        virtual void resetGenerationData(boost::shared_ptr<NEAT::GeneticGeneration> generation);

        virtual void addGenerationData(boost::shared_ptr<NEAT::GeneticGeneration> generation,boost::shared_ptr<NEAT::GeneticIndividual> individual);
    };

}

#endif // HCUBE_LOGICBUILDEREXPERIMENT_H_INCLUDED

