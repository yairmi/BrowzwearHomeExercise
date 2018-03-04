#include "stdafx.h"
#include "ArchiveBase.h"
#include "SerializeXML.h"
#include "SerializeTxt.h"
#include "SerializeAlgoorithmPrototypeFactory.h"
#include <Shlwapi.h>

namespace ArchiveBaseNs
{
	string getFileExt(const string& fileName)
	{
		std::string::size_type idx;
		std::string extension;
		idx = fileName.rfind('.');

		if (idx != std::string::npos)
		{
			extension = fileName.substr(idx + 1);
		}

		return extension;
	}
}

ArchiveBase::ArchiveBase(string fileName)
{
	m_sFileName = fileName;
	string fileExt = ArchiveBaseNs::getFileExt(m_sFileName);
	SerializeAlgoorithmPrototypeFactory &factory = SerializeAlgoorithmPrototypeFactory::GetInstance();
	m_serializeAlgorithm = factory.createPrototype(fileExt);
}


ArchiveBase::~ArchiveBase()
{
}
