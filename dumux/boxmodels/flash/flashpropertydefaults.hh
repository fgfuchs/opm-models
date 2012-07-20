// -*- mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
// vi: set et ts=4 sw=4 sts=4:
/*****************************************************************************
 *   Copyright (C) 2008 by Klaus Mosthaf, Andreas Lauser, Bernd Flemisch     *
 *   Institute for Modelling Hydraulic and Environmental Systems             *
 *   University of Stuttgart, Germany                                        *
 *   email: <givenname>.<name>@iws.uni-stuttgart.de                          *
 *                                                                           *
 *   This program is free software: you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation, either version 2 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 *****************************************************************************/
/*!
 * \file
 * \ingroup Properties
 * \ingroup BoxProperties
 * \ingroup FlashModel
 *
 * \brief Defines default values for most properties required by the
 *        flash box model.
 */
#ifndef DUMUX_FLASH_PROPERTY_DEFAULTS_HH
#define DUMUX_FLASH_PROPERTY_DEFAULTS_HH

#include "flashmodel.hh"
#include <dumux/boxmodels/common/boxmultiphaseproblem.hh>
#include "flashprimaryvariables.hh"
#include "flashratevector.hh"
#include "flashboundaryratevector.hh"
#include "flashvolumevariables.hh"
#include "flashfluxvariables.hh"
#include "flashindices.hh"
#include "flashproperties.hh"

#include <dumux/material/fluidmatrixinteractions/mp/nullmateriallaw.hh>
#include <dumux/material/heatconduction/dummyheatconductionlaw.hh>

namespace Dumux
{

namespace Properties {
//////////////////////////////////////////////////////////////////
// Property values
//////////////////////////////////////////////////////////////////

/*!
 * \brief Set the property for the number of components.
 */
SET_INT_PROP(BoxFlash, NumComponents, GET_PROP_TYPE(TypeTag, FluidSystem)::numComponents);

/*!
 * \brief Set the property for the number of fluid phases.
 */
SET_INT_PROP(BoxFlash, NumPhases, GET_PROP_TYPE(TypeTag, FluidSystem)::numPhases);

/*!
 * \brief Set the number of PDEs to the number of compontents
 */
SET_INT_PROP(BoxFlash, 
             NumEq,
             GET_PROP_VALUE(TypeTag, NumComponents));

/*!
 * \brief Set the property for the material law to the dummy law.
 */
SET_TYPE_PROP(BoxFlash,
              MaterialLaw, 
              Dumux::NullMaterialLaw<GET_PROP_VALUE(TypeTag, NumPhases), typename GET_PROP_TYPE(TypeTag, Scalar)>);

/*!
 * \brief Set the property for the material parameters by extracting
 *        it from the material law.
 */
SET_TYPE_PROP(BoxFlash,
              MaterialLawParams, 
              typename GET_PROP_TYPE(TypeTag, MaterialLaw)::Params);

//! set the heat conduction law to a dummy one by default
SET_TYPE_PROP(BoxFlash,
              HeatConductionLaw,
              Dumux::DummyHeatConductionLaw<typename GET_PROP_TYPE(TypeTag, Scalar)>);

//! extract the type parameter objects for the heat conduction law
//! from the law itself
SET_TYPE_PROP(BoxFlash,
              HeatConductionLawParams,
              typename GET_PROP_TYPE(TypeTag, HeatConductionLaw)::Params);

//! Use the FlashLocalResidual function for the flash model
SET_TYPE_PROP(BoxFlash,
              LocalResidual,
              FlashLocalResidual<TypeTag>);

//! the Model property
SET_TYPE_PROP(BoxFlash, Model, FlashModel<TypeTag>);

//! The type of the base base class for actual problems
SET_TYPE_PROP(BoxFlash, BaseProblem, BoxMultiPhaseProblem<TypeTag>);

//! the PrimaryVariables property
SET_TYPE_PROP(BoxFlash, PrimaryVariables, FlashPrimaryVariables<TypeTag>);

//! the RateVector property
SET_TYPE_PROP(BoxFlash, RateVector, FlashRateVector<TypeTag>);

//! the BoundaryRateVector property
SET_TYPE_PROP(BoxFlash, BoundaryRateVector, FlashBoundaryRateVector<TypeTag>);

//! the VolumeVariables property
SET_TYPE_PROP(BoxFlash, VolumeVariables, FlashVolumeVariables<TypeTag>);

//! the FluxVariables property
SET_TYPE_PROP(BoxFlash, FluxVariables, FlashFluxVariables<TypeTag>);

//! The indices required by the flash-baseed isothermal compositional model
SET_TYPE_PROP(BoxFlash, Indices, FlashIndices</*PVIdx=*/0>);

// disable the smooth upwinding method by default
SET_BOOL_PROP(BoxFlash, EnableSmoothUpwinding, false);
}

}

#endif