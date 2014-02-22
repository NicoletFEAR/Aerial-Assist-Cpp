#include "RunCompressor.h"
#include "../Robotmap.h"

static Compressor* compressor = NULL;

RunCompressor::RunCompressor()
	:CommandBase("RunCompressor")
{
}

void RunCompressor::Initialize()
{
	if(!compressor) compressor = new Compressor(kPressureSwitchChannel, kCompressorRelayChannel);
	compressor->Start();
}

void RunCompressor::Execute()
{
}

bool RunCompressor::IsFinished()
{
	return false;
}

void RunCompressor::End()
{
	compressor->Stop();
}

void RunCompressor::Interrupted()
{
	End();
}
