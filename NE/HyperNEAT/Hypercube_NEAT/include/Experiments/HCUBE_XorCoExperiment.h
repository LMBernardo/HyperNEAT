#ifndef HCUBE_XORCOEXPERIMENT_H_INCLUDED
#define HCUBE_XORCOEXPERIMENT_H_INCLUDED

#include "HCUBE_Experiment.h"

#ifdef EPLEX_INTERNAL

namespace HCUBE
{
    class XorCoExperiment : public Experiment, public NEAT::CoEvoExperiment
    {
    protected:

    public:
        XorCoExperiment(string _experimentName,int _threadID);

        virtual ~XorCoExperiment()
        {}

        virtual NEAT::GeneticPopulation* createInitialPopulation(int populationSize);

        pair<double,double> playGame(
            boost::shared_ptr<NEAT::GeneticIndividual> firstPlayer,
            boost::shared_ptr<NEAT::GeneticIndividual> secondPlayer
        );

        virtual void processGroup(boost::shared_ptr<NEAT::GeneticGeneration> generation);

        virtual void processIndividualPostHoc(boost::shared_ptr<NEAT::GeneticIndividual> individual);

#ifndef HCUBE_NOGUI
        virtual void createIndividualImage(wxDC &drawContext,boost::shared_ptr<NEAT::GeneticIndividual> individual)
        {}
#endif

        virtual bool performUserEvaluations()
        {
            return false;
        }

#ifndef HCUBE_NOGUI
        /**
         * handleMousePress: returns true if the window needs to be refreshed
         */
        virtual bool handleMousePress(wxMouseEvent& event,wxSize &bitmapSize)
        {
            return false;
        }

        /**
         * handleMouseMotion: returns true if the window needs to be refreshed
         */
        virtual bool handleMouseMotion(wxMouseEvent& event,wxDC &temp_dc,boost::shared_ptr<NEAT::GeneticIndividual> individual)
        {
            return false;
        }
#endif

        virtual inline bool isDisplayGenerationResult()
        {
            return displayGenerationResult;
        }

        virtual inline void setDisplayGenerationResult(bool _displayGenerationResult)
        {
            displayGenerationResult=_displayGenerationResult;
        }

        virtual inline void toggleDisplayGenerationResult()
        {
            displayGenerationResult=!displayGenerationResult;
        }

#ifndef HCUBE_NOGUI
        inline void drawPixel(int x,int y,int relativeResolution,wxColour** localBuffer,wxColour value)
        {
            //you want to draw a pixel at x,y if x,y was over 32, so multiply if it isn't

            int mody,modx;
            for (mody=0;mody<relativeResolution;mody++)
            {
                for (modx=0;modx<relativeResolution;modx++)
                {
                    localBuffer[(y*relativeResolution)+mody][(x*relativeResolution)+modx] = value;
                }
            }
        }
#endif

        virtual Experiment* clone();

        virtual void resetGenerationData(boost::shared_ptr<NEAT::GeneticGeneration> generation)
        {}

        virtual void addGenerationData(boost::shared_ptr<NEAT::GeneticGeneration> generation,boost::shared_ptr<NEAT::GeneticIndividual> individual);

    };
}

#endif

#endif // HCUBE_XORCOEXPERIMENT_H_INCLUDED
