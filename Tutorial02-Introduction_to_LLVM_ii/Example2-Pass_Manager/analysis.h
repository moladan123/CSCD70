#include <llvm/Pass.h>

using namespace llvm;

class Analysis : public ModulePass
{
private:
	std::vector < unsigned > _my_stats;
public:
	static char ID;

	Analysis() : ModulePass(ID) {}

	virtual ~Analysis() {}

	virtual void getAnalysisUsage(AnalysisUsage & AU) const;
	virtual bool runOnModule(Module & M);
	// Return the gathered statstics.
	std::vector < unsigned > getStats() const { return _my_stats; }
};
