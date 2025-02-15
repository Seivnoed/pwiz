﻿/*
 * Original author: Nicholas Shulman <nicksh .at. u.washington.edu>,
 *                  MacCoss Lab, Department of Genome Sciences, UW
 *
 * Copyright 2019 University of Washington - Seattle, WA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
using System;

namespace pwiz.Common.DataBinding.Attributes
{
    /// <summary>
    /// Allows the name of a property to be overridden.
    /// </summary>
    [AttributeUsage(AttributeTargets.Property | AttributeTargets.Class | AttributeTargets.Struct)]
    public class InvariantDisplayNameAttribute : InUiModesAttribute
    {
        public InvariantDisplayNameAttribute(string displayName)
        {
            InvariantDisplayName = displayName;
        }
        public string InvariantDisplayName { get; private set; }
        public ColumnCaption ColumnCaption { get {return new ColumnCaption(InvariantDisplayName);} }
    }
}
