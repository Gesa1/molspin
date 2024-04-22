/////////////////////////////////////////////////////////////////////////
// TaskStaticHSStochTimeEvo (RunSection module) by Gediminas Pazera and Luca Gerhards
// ------------------
//
// Molecular Spin Dynamics Software - developed by Claus Nielsen and Luca Gerhards.
// (c) 2019 Quantum Biology and Computational Physics Group.
// See LICENSE.txt for license information.
/////////////////////////////////////////////////////////////////////////
#ifndef MOD_RunSection_TaskStaticHSStochTimeEvo
#define MOD_RunSection_TaskStaticHSStochTimeEvo

#include "BasicTask.h"
#include "SpinAPIDefines.h"

namespace RunSection
{
	class TaskStaticHSStochTimeEvo : public BasicTask
	{
	private:
		SpinAPI::ReactionOperatorType reactionOperators;
		bool productYieldsOnly;			  // If true, a quantum yield will be calculated from each Transition object and multiplied by the rate constant
										  // If false, a quantum yield will be calculated each defined State object
		void WriteHeader(std::ostream &); // Write header for the output file

	protected:
		bool RunLocal() override;
		bool Validate() override;

	public:
		// Constructors / Destructors
		TaskStaticHSStochTimeEvo(const MSDParser::ObjectParser &, const RunSection &); // Normal constructor
		~TaskStaticHSStochTimeEvo();												   // Destructor
		bool is_identity_matrix(arma::sp_cx_mat &matrix);							   // check if the matrix is an identity
	};
}

#endif
