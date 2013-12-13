// -*- mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
// vi: set et ts=4 sw=4 sts=4:
/*
  Copyright (C) 2008-2013 by Andreas Lauser

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/
/*!
 * \file
 *
 * \brief test for the compositional PVS VCVF discretization
 */
#include "config.h"

#include <ewoms/common/start.hh>
#include <ewoms/models/pvs/pvsmodel.hh>
#include "problems/outflowproblem.hh"

namespace Opm {
namespace Properties {
NEW_TYPE_TAG(OutflowProblem, INHERITS_FROM(PvsModel, OutflowBaseProblem));

// Verbosity of the PVS model (0=silent, 1=medium, 2=chatty)
SET_INT_PROP(OutflowProblem, PvsVerbosity, 1);
}
}

int main(int argc, char **argv)
{
    typedef TTAG(OutflowProblem) ProblemTypeTag;
    return Ewoms::start<ProblemTypeTag>(argc, argv);
}